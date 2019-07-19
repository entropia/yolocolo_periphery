#pragma once
#include <stddef.h>

static const char START_BYTE = 0x02;
static const char STOP_BYTE = 0x03;
static const char SET_BYTE = 'J';

static const size_t ADDRESS_LENGTH = sizeof(unsigned short);
static const size_t NAME_LENGTH = 10;
static const size_t STATE_LENGTH = sizeof(unsigned short);
static const size_t ALARM_LENGTH = sizeof(char);
static const size_t CHECKSUM_LENGTH = sizeof(unsigned short);

static const size_t SET_FIRST_UNKNOWN_LENGTH = 18;
static const size_t SET_SECOND_UNKNOWN_LENGTH = 3;
static const size_t SET_COMMAND_LENGTH = 40; 

//returns new pos
size_t pad0(size_t count, size_t pos, char *dst);

//Add's start and stop byte to frame
//Requires a buffer of srcSize + 2
//Returns > 0 if successful
size_t wrapFrame(char *src, size_t srcSize, char *dst);
//Removes the start and stop byte from the frame
//Requires a buffer of srcSize - 2
//Returns srcSize - 2 if successful, else 0
size_t unwrapFrame(char *src, size_t srcSize, char *dst);

unsigned short calculateChecksum(char *src, size_t size);

//Does not print the created string
//Returns > 0 if successful
//Requires an dstSize of >= SET_COMMAND_LENGTH
size_t commandSet(unsigned char address, char *name, size_t nameSize,
		  	unsigned short switchState, unsigned short lowAlarm,
		 	unsigned highAlarm, char *dst);
