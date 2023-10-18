#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i = 0;
	cmd_t *cmds;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	cmds = (cmd_t *)malloc(sizeof(cmd_t));
	read_code(argv[1], cmds);
	parse(cmds);
	for (i = 0; i < cmds->line_count; i++)
		free(cmds->lines[i]);
	free(cmds);
	return (0);
}
