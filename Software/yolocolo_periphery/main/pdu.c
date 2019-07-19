#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "pdu.h"

//Add's start and stop byte to frame
size_t completeFrame(char* src, size_t srcSize, char** dst) {
	if(srcSize == 0) {
		return 0;
	}

	size_t dstSize = srcSize + 2 * sizeof(char);
	*dst = malloc(dstSize);

	**dst = START_BYTE;
	memcpy((*dst + 1), src, srcSize);
	*(*dst + 1 + srcSize) = STOP_BYTE;

	return dstSize;
}
