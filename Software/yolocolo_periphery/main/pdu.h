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

size_t pad0(size_t count, size_t pos, char* dst);

size_t completeFrame(char* src, size_t srcSize, char** dst);
unsigned short calculateChecksum(char* src, size_t size);

size_t commandSet(unsigned char address, char* name, size_t nameSize,
		  	unsigned short switchState, unsigned short lowAlarm,
		 	unsigned highAlarm, char *dst);
