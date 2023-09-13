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
	bool piped = false;

	(void)argc;
	while (!piped)
	{
		int tok = 0;

		cmd = getPrompt();
		if (isatty(STDIN_FILENO) == 0)
			piped = true;
		if (cmd == NULL)
		{
			cmd_count++;
			continue;
		}
		cmd = rmv_space(cmd);
		tok = tokenize_cmd(cmd, args);
		if (_strncmp("exit", args[0], 4) == 0)
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
