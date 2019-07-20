#pragma once
#include <stddef.h>
#include <stdbool.h>

static const char START_BYTE = 0x02;
static const char STOP_BYTE = 0x03;
static const char SET_BYTE = 'J';
static const char SET_RECV_BYTE = 'j';
static const char QUERRY_BYTE = 'I';
static const char QUERRY_RECV_BYTE = 'i';

static const size_t ADDRESS_LENGTH = sizeof(unsigned short);
#define NAME_LENGTH 10
static const size_t STATE_LENGTH = sizeof(unsigned short);
static const size_t POWER_LENGTH = 4;
static const size_t ALARM_LENGTH = sizeof(char);
static const size_t CHECKSUM_LENGTH = sizeof(unsigned short);
#define SOCKET_COUNT 6

static const size_t SET_COMMAND_LENGTH = 40; 
static const size_t SET_RECV_LENGTH = 3; 
static const size_t SET_FIRST_UNKNOWN_LENGTH = 18;
static const size_t SET_SECOND_UNKNOWN_LENGTH = 3;
static const size_t QUERRY_COMMAND_LENGTH = 5;
static const size_t QUERRY_RECV_LENGTH = 42;
static const size_t QUERRY_FIRST_UNKNOWN_LENGTH = 3;
static const size_t QUERRY_SECOND_UNKNOWN_LENGTH = 6;
static const size_t QUERRY_THIRD_UNKNOWN_LENGTH = 4;
static const size_t QUERRY_FOURTH_UNKNOWN_LENGTH = 8;

struct stSetSend {
	unsigned char address;
	char name[NAME_LENGTH + 1];
	bool socketState[SOCKET_COUNT];
	unsigned char lowAlarm;
	unsigned char HighAlarm;
};

struct stQuerryRecv {
	unsigned char address;
	char name[NAME_LENGTH + 1];
	unsigned short power;
	bool socketState[SOCKET_COUNT];
};

//returns new pos
size_t pad0(size_t count, size_t pos, char *dst);
unsigned short calculateChecksum(char *src, size_t size);
void decodeSocket(unsigned short encoded, bool socketState[SOCKET_COUNT]);
unsigned short encodeSocket(bool socketState[SOCKET_COUNT]);

//Add's start and stop byte to frame
//Requires a buffer of srcSize + 2
//Returns > 0 if successful
size_t wrapFrame(char *src, size_t srcSize, char *dst);
//Removes the start and stop byte from the frame
//Requires a buffer of srcSize - 2
//Returns srcSize - 2 if successful, else 0
size_t unwrapFrame(char *src, size_t srcSize, char *dst);


//Does not print the created string
//Returns > 0 if successful
//Requires an dstSize of >= SET_COMMAND_LENGTH
size_t commandSet(unsigned char address, char *name, size_t nameSize,
		  	unsigned short switchState, unsigned short lowAlarm,
		 	unsigned highAlarm, char *dst);
//Returns true if the received string is valid
bool recvSet(char *src);


//Does not print the created string
//Requires a buffer of >= QUERRY_COMMAND_LENGTH
//Returns QUERRY_COMMAND_LENGTH if successful, otherwise 0
size_t commandQuerry(unsigned char address, char *dst);
//Returns true if the received string is valid
bool recvQuerry(char *src, unsigned char address, struct stQuerryRecv *recv);
