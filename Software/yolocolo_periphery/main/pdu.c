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

size_t completeFrame(char *src, size_t srcSize, char *dst)
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

unsigned short calculateChecksum(char *src, size_t size) 
{
	if (size == 0) {
		printf("Checksum error: Length of src is zero");
		return 0;
	}

	unsigned short checksum = src[0];
	for (size_t i = 1; i < size; i++) {
		checksum ^= src[i];
	}

	return checksum;
}

size_t commandSet(unsigned char address, char *name, size_t nameSize,
		  	unsigned short switchState, unsigned short lowAlarm,
		 	unsigned highAlarm, char *dst)
{
	if (address == 0 || address > 8) {
		printf("Invalid address (%u)\n", address);
		return 0;
	}

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

	sprintf(&dst[pos], "%02hu", address);
	pos += ADDRESS_LENGTH;

	strcpy(&dst[pos], name);
	pos += nameSize;
	pos = pad0(NAME_LENGTH - nameSize, pos, dst);

	sprintf(&dst[pos], "%02hu", switchState);
	pos += STATE_LENGTH;

	sprintf(&dst[pos], "%0*d\n", SET_FIRST_UNKNOWN_LENGTH, 0); 
	pos += SET_FIRST_UNKNOWN_LENGTH;

	sprintf(&dst[pos], "%hX", lowAlarm);
	pos++;

	sprintf(&dst[pos], "%0*d\n", SET_SECOND_UNKNOWN_LENGTH, 0); 
	pos += SET_SECOND_UNKNOWN_LENGTH;

	sprintf(&dst[pos], "%hX", highAlarm);
	pos++;

	unsigned short checksum = calculateChecksum(dst, SET_COMMAND_LENGTH - CHECKSUM_LENGTH);

	sprintf(&dst[pos], "%hX", checksum);
	return SET_COMMAND_LENGTH;
}
