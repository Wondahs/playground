#include "main.h"

#define MAX_ARGS 128
int main(void)
{
	char *cmd, *token;
	char *fullPath;
	char *args[MAX_ARGS];
	/*char *envp[] = {NULL};*/

	while (1)
	{
		int j, i = 0;

		/* Get command */
		cmd = getPrompt();
		/* Check for exit command */
		if (_strncmp("exit", cmd, _strlen(cmd)) == 0)
		{
			printf("exiting\n");
			free(cmd);
			break;
		}
		/* Tokenize input */
		token = _strtok(cmd, " ");
		while (token != NULL && i < MAX_ARGS - 1)
		{
			args[i++] = _strdup(token);
			token = _strtok(NULL, " ");
		}
		args[i] = NULL;
		/* Check if command exixts */
		fullPath = checkPath(args[0]);
		if (fullPath == NULL)
		{
			write(STDOUT_FILENO, args[0], _strlen(args[0]));
			perror(">");
		}
		else
		{
			args[0] = fullPath;
			execve(args[0], args, NULL);
		}
		/* Free allocated memory */
		for (j = 0; j < i; j++)
		{
			free(args[j]);
			args[j] = NULL;
		}
		free(fullPath);
		free(cmd);
	}
	return (0);
}
