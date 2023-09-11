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
	bool Path = true;

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
		if (_strncmp(args[0], "exit", 4) == 0)
		{
			free(cmd);
			sh_exit(args, tok, cmd_count, argv[0], Path);
			cmd_count++;
			continue;
		}
		cl_exec(tok, args, cmd_count, argv[0], Path);
		free(cmd);
		cmd_count++;
	}
	return (0);
}
