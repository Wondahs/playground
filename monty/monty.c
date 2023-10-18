#include "monty.h"

cmd_t *cmds = NULL;
int main(int argc, char *argv[])
{
	int i = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	cmds = (cmd_t *)malloc(sizeof(cmd_t));
	read_code(argv[1], cmds);
	parse(cmds);
	execute();
	for (i = 0; i < cmds->line_count; i++)
		free(cmds->lines[i]);
	free(cmds);
	return (0);
}
