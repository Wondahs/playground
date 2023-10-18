#include "monty.h"
#include <stdio.h>

/**
 *
 *
 *
 *
 *
 *
 */
void read_code(char *argv_1)
{
	int bytesread = 0, written = 0;
	int file = open(argv_1, O_RDONLY);
	if (file == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv_1);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		bytesread = read(file, cmds->buffer, 1024);
		written += bytesread;
		if (bytesread == 0)
			break;
	}
	close(file);
	cmds->buffer[written] = '\0';
}
