#include "main.h"

int main(void)
{
	char *cmd;
	char *fullPath;
	/* char *argv[] = {NULL}; */
	/* char *envp[] = {NULL}; */

	while (1)
	{

		/* Get command */
		cmd = getPrompt();
		/* Check for exit command */
		if (_strncmp("exit", cmd, _strlen(cmd)) == 0)
		{
			free(cmd);
			break;
		}

		fullPath = checkPath(cmd);
		if (fullPath == NULL)
			perror("./shell");
		else
			printf("%s\n", fullPath);
		free(fullPath);
		free(cmd);
	}
	return 0;
}
