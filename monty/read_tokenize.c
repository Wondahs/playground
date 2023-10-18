#include "monty.h"
#include <stdlib.h>
#include <string.h>

/**
 *
 *
 *
 *
 *
 *
 */
char *read_code(char *argv_1)
{
	int bytesread, written = 0;
	int file = open(argv_1, O_RDONLY);
	char *buffer;
	if (file == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv_1);
		exit(EXIT_FAILURE);
	}

	buffer = malloc(1025);
	while (1)
	{
		bytesread = read(file, buffer, 1024);
		written += bytesread;
		if (bytesread == 0)
			break;
	}
	close(file);
	buffer[written] = '\0';
	return (buffer);
}
