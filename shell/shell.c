#include "main.h"

/**
 * main - This is the entry point of a custom UNIX command line interpreter
 * @argc: Argument count
 * @argv: Arguments vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int cmd_count = 1;
	char *cmd, *args[MAX_ARGS];

	(void)argc;
	while (1)
	{
		int tok = 0;
		/* Get command */
		cmd = getPrompt();
		if (cmd == NULL)
		{
			cmd_count++;
			continue;
		}
		cmd = rmv_space(cmd);
		tok = tokenize_cmd(cmd, args);
		if (tok == -1)
			break;
		call_exec(tok, args, cmd_count, argv[0]);
		free(cmd);
		cmd_count++;
	}
	return (0);
}
