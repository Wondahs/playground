#include "monty.h"
#include <stdio.h>

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
	int *i = &(cmds->line_count);

	*i = 0;
	token = strtok(buffer, "\n");
	while ((*i) < MAX_LINES && token != NULL)
	{
		cmds->lines[*i] = strdup(token);
		token = strtok(NULL, "\n");
		cmds->lines[*i] = rmv_space(cmds->lines[*i]);
		(*i)++;
	}
}
