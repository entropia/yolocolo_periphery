#pragma once
#include <stddef.h>

static const char START_BYTE = 0x02;
static const char STOP_BYTE = 0x03;

size_t completeFrame(char* src, size_t srcSize, char** dst);
