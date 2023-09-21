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
	size_t i = 0;

	for (i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
		if (_strncmp(cmd_name, commands.name[i],
					_strlen(commands.name[i])) == 0)
			return (commands.func[i]);
}
