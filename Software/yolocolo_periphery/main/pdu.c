#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pdu.h"

size_t pad0(size_t count, size_t pos, char *dst)
{
	for (size_t i = 0; i < pos + count; i++) {
		dst[pos + i] = 0;	
	}

	return pos + count;
}

void decodeSocket(unsigned char encoded, bool socketState[SOCKET_COUNT])
{
	for (size_t i = 0; i < SOCKET_COUNT; i++) {
		socketState[i] = encoded & (1 << i);
	}

}

unsigned short encodeSocket(bool socketState[SOCKET_COUNT])
{ 
	unsigned short encoded = 0;
	for (size_t i = 0; i < SOCKET_COUNT; i++) {
		encoded += socketState[i] << i;
	}

	return encoded;
}

size_t wrapFrame(char *src, size_t srcSize, char *dst)
{
	if(srcSize == 0) {
		return 0;
	}

	size_t dstSize = srcSize + 2 * sizeof(char);
	
	dst[0] = START_BYTE;
	memcpy(&dst[1], src, srcSize);
	dst[dstSize - 1] = STOP_BYTE;

	return dstSize;
}

size_t unwrapFrame(char *src, size_t srcSize, char *dst)
{
	if (srcSize < 2) {
		printf("Too short frame\n");
		return 0;
	}

	if (src[0] != START_BYTE) {
		printf("Start byte of frame is invalid: (%hhX)\n", src[0]);
		return 0;
	}
	if (src[srcSize - 1] != STOP_BYTE) {
		printf("Stop byte of frame is invalid: (%hhX)\n", src[srcSize -1]);
		return 0;
	}

	memcpy(dst, &src[1], srcSize - 2);

	return srcSize - 2;
}

unsigned char calculateChecksum(char *src, size_t size) 
{
	if (size == 0) {
		printf("Checksum error: Length of src is zero");
		return 0;
	}

	unsigned char checksum = src[0];
	for (size_t i = 1; i < size; i++) {
		checksum ^= src[i];
	}

	return checksum;
}

size_t commandSet(struct stSetSend *send, char *dst)
{
	if (send->address == 0 || send->address > 8) {
		printf("Invalid address (%u)\n", send->address);
		return 0;
	}
	
	size_t nameSize = strlen(send->name);
	if (nameSize == 0) {
		printf("Name has a length of zero\n");
		return 0;
	//Case: \0 falls on 11th byte
	} else if (nameSize > (NAME_LENGTH + 1)) {
		printf("Name too long\n");
	} else if (nameSize == (NAME_LENGTH + 1)) {
		nameSize--;
	}

	size_t pos = 0;
	dst[pos] = SET_BYTE;
	pos++;

	sprintf(&dst[pos], "%02hu", send->address);
	pos += ADDRESS_LENGTH;

	strcpy(&dst[pos], send->name);
	pos += nameSize;
	pos = pad0(NAME_LENGTH - nameSize, pos, dst);

	unsigned char socketState = encodeSocket(send->socketState);
	sprintf(&dst[pos], "%02hu", socketState);
	pos += STATE_LENGTH;

	sprintf(&dst[pos], "%0*d\n", SET_FIRST_UNKNOWN_LENGTH, 0); 
	pos += SET_FIRST_UNKNOWN_LENGTH;

	sprintf(&dst[pos], "%hX", send->lowAlarm);
	pos++;

	sprintf(&dst[pos], "%0*d\n", SET_SECOND_UNKNOWN_LENGTH, 0); 
	pos += SET_SECOND_UNKNOWN_LENGTH;

	sprintf(&dst[pos], "%hX", send->highAlarm);
	pos++;

	unsigned char checksum = calculateChecksum(dst, SET_COMMAND_LENGTH - CHECKSUM_LENGTH);

	sprintf(&dst[pos], "%hX", checksum);
	return SET_COMMAND_LENGTH;
}

bool recvSet(char *src)
{
	if (src[0] != SET_RECV_BYTE) {
		return false;
	}

	char temp[CHECKSUM_LENGTH + 1];
	sprintf(temp, "%hX", SET_RECV_BYTE);

	return !strncmp(temp, &src[1], CHECKSUM_LENGTH);	
}

size_t commandQuerry(unsigned char address, char *dst) 
{
	if (address == 0 || address >= 8) {
		printf("Invalid address: (%hhu)\n", address);
	}

	size_t pos = 0;

	dst[pos] = QUERRY_BYTE;
	pos++;

	sprintf(&dst[pos], "%hX", address);
	pos += ADDRESS_LENGTH;
	
	unsigned char checksum = calculateChecksum(dst, QUERRY_COMMAND_LENGTH - CHECKSUM_LENGTH);
	sprintf(&dst[pos], "%hX", checksum);

	return QUERRY_COMMAND_LENGTH;
}

bool recvQuerry(char *src, unsigned char address, struct stQuerryRecv *recv)
{
	char tempHexBuffer[CHECKSUM_LENGTH + 1];

	memcpy(tempHexBuffer, &src[QUERRY_RECV_LENGTH - CHECKSUM_LENGTH - 1], CHECKSUM_LENGTH);
	tempHexBuffer[CHECKSUM_LENGTH] = 0;
	unsigned char checksum = strtoul(tempHexBuffer, NULL, 16);
	unsigned char tempChecksum = calculateChecksum(src, QUERRY_RECV_LENGTH - CHECKSUM_LENGTH);
	if (checksum != tempChecksum) {
		printf("Calcalated Checksum: (%hhx) differs from sent Checksum: (%hhx)",
				tempChecksum, checksum);
		return 0;
	}


	size_t pos = 0;
	
	if (src[pos] != QUERRY_RECV_BYTE) {
		return false;
	}
	pos++;

	sprintf(tempHexBuffer, "%hhu", address);
	if (!strncmp(tempHexBuffer, &src[pos], ADDRESS_LENGTH)) {
		printf("Addresses do not match\n");
		return false;
	}
	pos += QUERRY_FIRST_UNKNOWN_LENGTH;

	memcpy(recv->name, &src[pos], NAME_LENGTH);
	//\0-terminate
	if (src[pos + NAME_LENGTH - 1] == 0) {
		recv->name[NAME_LENGTH] = 0;
	}
	pos += QUERRY_SECOND_UNKNOWN_LENGTH;

	char powerBuffer[POWER_LENGTH + 1];
	memcpy(powerBuffer, &src[pos], POWER_LENGTH);
	powerBuffer[POWER_LENGTH] = 0;
	//hex-string
	recv->power = (unsigned short) strtoul(powerBuffer, NULL, 16);
	pos += POWER_LENGTH;
	pos += QUERRY_THIRD_UNKNOWN_LENGTH;

	memcpy(tempHexBuffer, &src[pos], NAME_LENGTH + 1);
	unsigned char tempEncoded = strtoul(tempHexBuffer, NULL, 16);
	decodeSocket(tempEncoded, recv->socketState);

	return true;
}
