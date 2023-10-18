#include "monty.h"

/**
 *rmv_space - Removes unnecessary character from input string
 *@cmd: Input string
 *
 *Return: Corrected string
 */
char *rmv_space(char *cmd)
{
	int i, j = 0;
	char *cmd_clean;
	bool prev_space = (cmd[0] == ' ' || cmd[0] == '\t');

	cmd_clean = malloc(strlen(cmd) + 1);

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == ' ' || cmd[i] == '\t')
		{
			if (!prev_space)
				cmd_clean[j++] = cmd[i];
			prev_space = true;
		}
		else
		{
			cmd_clean[j++] = cmd[i];
			prev_space = false;
		}
	}
	cmd_clean[j] = '\0';
	free(cmd);
	cmd = cmd_clean;
	return (cmd);
}

/**
 *
 *
 *
 *
 *
 *
 */
void parse(cmd_t *cmds)
{
	char *buffer = cmds->buffer;
	char *token = NULL;
	int i = 0;

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
}
