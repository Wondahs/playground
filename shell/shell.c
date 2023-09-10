#include "main.h"
#include "printf.h"

#define MAX_ARGS 128
int main(int argc, char *argv[])
{
	int cmd_count = 1;
	char *cmd, *token, *fullPath, *args[MAX_ARGS];

	(void)argc;
	while (1)
	{
		int j, i = 0;

		/* Get command */
		cmd = getPrompt();
		if (cmd == NULL)
		{
			cmd_count++;
			continue;
		}
		/* Tokenize input */
		token = _strtok(cmd, " ");
		while (token != NULL && i < MAX_ARGS - 1)
		{
			args[i++] = _strdup(token);
			token = _strtok(NULL, " ");
		}
		args[i] = NULL;
		if (_strncmp(args[0], "exit", 4) == 0)
			break;
		/* Check if command exixts */
		fullPath = checkPath(args[0]);
		if (fullPath == NULL)
		{
			_printf("%s: %i: %s: not found\n", argv[0], cmd_count, args[0]);
		/* Free allocated memory */
			for (j = 0; j < i; j++)
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
