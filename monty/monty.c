#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i = 0;
	char *buffer = NULL, *token = NULL;
	cmd_t *cmds;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	cmds = (cmd_t *)malloc(sizeof(cmd_t));
	read_code(argv[1], cmds);
	buffer = cmds->buffer;
	cmds->line_count = 0;
	token = strtok(buffer, "\n");
	while (cmds->line_count < MAX_LINES && token != NULL)
	{
		cmds->lines[(cmds->line_count)++] = strdup(token);
		token = strtok(NULL, "\n");
	}

	for (i = 0; i < cmds->line_count; i++)
	{
		int args = 0;

		cmds->lines[i] = rmv_space(cmds->lines[i]);
		token = strtok(cmds->lines[i], " ");
		while (args < MAX_ARGS && token != NULL)
		{
			cmds->args[args] = (token);
			token = strtok(NULL, " ");
			args++;
		}
		printf("cmd: %s, num: %s\n", cmds->args[0], cmds->args[1]);
	}
	for (i = 0; i < cmds->line_count; i++)
		free(cmds->lines[i]);
	free(cmds);
	return (0);
}
