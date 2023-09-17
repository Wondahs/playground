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
	char *cmd, *args[MAX_ARGS], *seps[MAX_ARGS];
	bool Path = true;
	bool piped = false;

	(void)argc;
	while (!piped)
	{
		int cmds, i, tok = 0;

		cmd = getPrompt();
		if (isatty(STDIN_FILENO) == 0)
			piped = true;
		if (cmd == NULL)
		{
			cmd_count++;
			continue;
		}
		cmd = rmv_space(cmd);
		cmds = tokenize_cmd(cmd, seps, ";");
		free(cmd);
		for (i = 0; i < cmds; i++)
		{
			seps[i] = rmv_space(seps[i]);
			tok = tokenize_cmd(seps[i], args, " ");
			if (_strncmp("exit", args[0], _strlen(args[0])) == 0)
			{
				_ext(args, tok, cmd_count, i, argv[0], Path, seps);
				cmd_count++;
				continue;
			}
			cl_exec(tok, args, cmd_count, argv[0], Path);
			free(seps[i]);
			cmd_count++;
		}
		free(seps[cmds]);
	}
	return (0);
}
