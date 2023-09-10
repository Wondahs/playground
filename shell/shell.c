#include "main.h"
#include "printf.h"

#define MAX_ARGS 128
int main(int argc, char *argv[])
{
	int cmd_count = 1;
	char *cmd, *fullPath, *args[MAX_ARGS];

	(void)argc;
	while (1)
	{
		int j, tok = 0;

		/* Get command */
		cmd = getPrompt();
		if (cmd == NULL)
		{
			cmd_count++;
			continue;
		}
		tok = tokenize_cmd(cmd, args);
		if (tok == -1)
			break;
		/* Check if command exixts */
		fullPath = checkPath(args[0]);
		if (fullPath == NULL)
		{
			_printf("%s: %i: %s: not found\n", argv[0], cmd_count, args[0]);
		/* Free allocated memory */
			for (j = 0; j < tok; j++)
			{
				free(args[j]);
				args[j] = NULL;
			}
			free(fullPath);
		}
		else
		{
			free(args[0]);
			args[0] = fullPath;
			execute(args);
		}
		/*free(fullPath);*/
		free(cmd);
		cmd_count++;
	}
	return (0);
}
