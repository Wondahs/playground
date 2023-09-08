#include "main.h"

int main(void)
{
	char *c = NULL;
	char *fullPath;
	/* char *argv[] = {NULL}; */
	/* char *envp[] = {NULL}; */
	int n = 10;
	ssize_t i;

	while (1)
	{
		char *c_cpy;
		/* Flush stdout and show prompt */
		printf("$ ");
		fflush(stdout);
		/* Get command */
		i = _getline(&c, &n, STDIN_FILENO);
		/* Set string terminator and duplicate command */
		c[i - 1] = '\0';
		c_cpy = _strdup(c);
		if (!c_cpy)
			perror("strdup error");
		/* Check for exit command */
		if (_strncmp("exit", c_cpy, _strlen(c_cpy)) == 0)
		{
			free(c_cpy);
			free(c);
			break;
		}
		/* Check if command exists */
		fullPath = checkPath(c_cpy);
		if (fullPath == NULL)
			perror("./shell");
		else
			printf("%s\n", fullPath);
		
		free(c_cpy);
	}
	return 0;
}
