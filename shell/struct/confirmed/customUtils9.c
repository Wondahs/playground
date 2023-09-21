#include "main.h"

/**
 *
 *
 *
 *
 *
 *
 */
bool sCases(cmd_t *cmmds, cmd_t *args, int cmd_count,                   int i, char *argv_0)
{
	char *cmd_name = args->args[0];
	size_t j = 0;

	sCases_t commands[] =
	{
		{"setenv", cmd_setenv},
		{"unsetenv", cmd_unsetenv},
		{"exit", cmd_exit},
		{"env", cmd_env},
	};
	for (j = 0; j < sizeof(commands) / sizeof(commands[0]); j++)
	{
		if (_strncmp(cmd_name, commands[j].name,
					_strlen(commands[j].name)) == 0)
			return (commands[j].func(args, cmmds, cmd_count, i, argv_0));
	}

	return (false);
}

bool cmd_setenv(cmd_t *args, cmd_t *cmmds, int cmd_count, int i, char *argv_0)
{
	int condition = _setenv(args->args[1], args->args[2]);

	(void)cmmds;
	(void)cmd_count;
	(void)i;
	(void)argv_0;
	if (condition == -1)
		perror("_setenv");
	return (true);
}

bool cmd_unsetenv(cmd_t *args, cmd_t *cmmds, int cmd_count, int i, char *argv_0)
{
	int condition = _unsetenv(args->args[1]);

	(void)cmmds;
	(void)cmd_count;
	(void)i;
	(void)argv_0;
	if (condition == -1)
		perror("_setenv");
	return (true);
}

bool cmd_exit(cmd_t *args, cmd_t *cmmds, int cmd_count, int i, char *argv_0)
{
	_ext(cmmds, args, cmd_count, i, argv_0);
	return (true);
}

bool cmd_env(cmd_t *args, cmd_t *cmmds, int cmd_count, int i, char *argv_0)
{
	(void)cmmds;
	(void)cmd_count;
	(void)i;
	(void)argv_0;
	(void)args;
	print_env();

	return (true);
}
