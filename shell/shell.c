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
	bool Path = true, piped = false;
	cmd_t *cmmds, *args;

	(void)argc;
	cmmds = (cmd_t *)malloc(sizeof(cmd_t));
	args = (cmd_t *)malloc(sizeof(cmd_t));
	while (!piped)
	{
		int i;

		args->arg_count = 0;
		cmmds->arg_count = 0;
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
		for (i = 0; i < cmmds->arg_count; i++)
		{
			cmmds->args[i] = rmv_space(cmmds->args[i]);
			args->arg_count = tokenize_cmd(cmmds->args[i], args->args, " ");
			if (_strncmp("exit", args->args[0], _strlen(args->args[0])) == 0)
			{
				_ext(cmmds, args, cmd_count, i, argv[0], Path);
				cmd_count++;
				continue;
			}
			cl_exec(args, cmd_count, argv[0], Path);
			free(cmmds->args[i]);
			cmd_count++;
		}
	}
	return (0);
}

/**
 * init_cmd_t - Initializes cmd_t struct
