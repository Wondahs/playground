#include "main.h"

/**
 *looper - Handles command execution.
 *@cmmds: Struct holding information of commands separated by ";"
 *@args: Struct holding information of commands.
 *@argv_0: Name of program held in argv[0].
 *@cmd_count: Pointer to number of commands executed.
 *
 *Return: Nothing.
 */
void looper(cmd_t *cmmds, cmd_t *args, char *argv_0, int *cmd_count)
{
	int i;
	bool Path = true;

	for (i = 0; i < cmmds->arg_count; i++)
	{
		cmmds->args[i] = rmv_space(cmmds->args[i]);
		args->arg_count = tokenize_cmd(cmmds->args[i], args->args, " ");
		if (_strncmp("exit", args->args[0], _strlen(args->args[0])) == 0)
		{
			_ext(cmmds, args, *cmd_count, i, argv_0, Path);
			(*cmd_count)++;
			continue;
		}
		cl_exec(args, *cmd_count, argv_0, Path);
		free(cmmds->args[i]);
		(*cmd_count)++;
	}
}

/**
 * init_cmd_t - Initializes cmd_t struct.
 *
 * This function initializes a cmd_t object that will be uses in main program.
 *
 * Return: Initialized cmd_t object
 */
cmd_t *init_cmd_t()
{
	cmd_t *cmmds;

	cmmds = (cmd_t *)malloc(sizeof(cmd_t));
	if (!cmmds)
		perror("malloc - cmmds");
	cmmds->arg_count = 0;
	return (cmmds);
}
