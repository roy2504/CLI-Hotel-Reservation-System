#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"
#include <string.h>


void removeTrailingNewLine(char* buffer)
{
	for (int i = 0; i < strlen(buffer); i++)
		if (buffer[i] == '\n')
			buffer[i] = '\0';
}
