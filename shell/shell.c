#include "main.h"

int main(void)
{
	char *c = NULL;
	char *token;
	char *envir;
	/*char *argv[] = {NULL};*/
	/*char *envp[] = {NULL};*/
	int n = 10;
	ssize_t i;

	while (1)
	{
		char *c_cpy;

		printf("$ Enter Name: ");
		fflush(stdout);

		i = _getline(&c, &n, STDIN_FILENO);
		c[i - 1] = '\0';
		c_cpy = _strdup(c);
		if (!c_cpy)
			perror("strdup error");
		if (_strncmp("exit", c_cpy, _strlen(c_cpy)) == 0)
		{
			free(c_cpy);
			free(c);
			break;
		}

		envir = _getenv(c_cpy);
		if (envir == NULL)
			perror("_getenv");

		token = _strtok(envir, ":");
		while (token != NULL)
		{
			printf("%s\n", token);
			token = _strtok(NULL, ":");
		}

		free(c_cpy);
	}
	return 0;
}
