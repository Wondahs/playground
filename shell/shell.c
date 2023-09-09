#include "main.h"

int main(void)
{
	char *cmd, *token;
	char *fullPath;
	int i = 0;
	char *args[] = {NULL};
	/*char *envp[] = {NULL};*/

	while (1)
	{
		/* Get command */
		cmd = getPrompt();

		/* Tokenize input */
		token = _strtok(cmd, " ");
		while (token != NULL)
		{
			args[i++] = token;
			token = _strtok(NULL, " ");
		}
		args[i] = NULL;

		/* Check for exit command */
		if (_strncmp("exit", args[0], _strlen(args[0]) == 0))
		{
			free(cmd);
			break;
		}

		/* Check if command exixts */
		fullPath = checkPath(args[0]);
		if (fullPath == NULL)
			perror("./shell");
		else
		{
			args[0] = fullPath;
			execve(args[0], args, NULL);
		}
		free(fullPath);
		free(cmd);
	}
	return (0);
}
