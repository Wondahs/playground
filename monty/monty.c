#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i = 0;
	char *buffer = NULL, *token = NULL;
	cmd_t *cmds;
	//stack_t *stack;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	buffer = read_code(argv[1]);
	cmds = (cmd_t *)malloc(sizeof(cmd_t));
	//stack = (stack_t *)malloc(sizeof(stack_t));
	cmds->line_count = 0;
	token = strtok(buffer, "\n");
	while (cmds->line_count < MAX_LINES && token != NULL)
	{
		cmds->lines[(cmds->line_count)++] = strdup(token);
		token = strtok(NULL, "\n");
	}
	free(buffer);

	for (i = 0; i < cmds->line_count; i++)
	{
		int args = 0;

		token = strtok(cmds->lines[i], " ");
		while (args < MAX_ARGS && token != NULL)
		{
			cmds->args[args] = strdup(token);
			token = strtok(NULL, " ");
			args++;
		}
		printf("cmd: %s, num: %s\n", cmds->args[0], cmds->args[1]);
	}
	for (i = 0; i < MAX_ARGS; i++)
		free(cmds->args[i]);
	for (i = 0; i < cmds->line_count; i++)
		free(cmds->lines[i]);
	free(cmds);
	return (0);
}
