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
	char *cmd;
	bool piped = false;
	cmd_t *cmmds, *args;

	(void)argc;
	cmmds = init_cmd_t();
	args = init_cmd_t();
	while (!piped)
	{
		cmd = getPrompt(cmmds, args);
		if (isatty(STDIN_FILENO) == 0)
			piped = true;
		if (cmd == NULL)
		{
			cmd_count++;
			continue;
		}
		cmd = rmv_space(cmd);
		cmmds->arg_count = tokenize_cmd(cmd, cmmds->args, ";");
		free(cmd);
		looper(cmmds, args, argv[0], &cmd_count);
	}
	return (0);
}
