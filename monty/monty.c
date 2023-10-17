#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int file, bytesread, written = 0, i = 0;
	char buffer[1024], *token = NULL;
	cmd_t *cmds;
	//stack_t *stack;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		bytesread = read(file, buffer, sizeof(buffer));
		written += bytesread;
		if (bytesread == 0)
			break;
	}
	close(file);
	buffer[written] = '\0';

	cmds = (cmd_t *)malloc(sizeof(cmd_t));
	//stack = (stack_t *)malloc(sizeof(stack_t));
	cmds->line_count = 0;

	token = strtok(buffer, "\n");
	while (token != NULL)
	{
		cmds->lines[(cmds->line_count)++] = strdup(token);
		token = strtok(NULL, "\n");
	}
	while (i < cmds->line_count)
		printf("%s\n", cmds->lines[i++]);

	for (i = 0; i < cmds->line_count; i++)
		free(cmds->lines[i]);
	free(cmds);
	return (0);
}
