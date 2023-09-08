#include "main.h"

int main(void)
{
	char *c = NULL;
	char *token;
	char *envir;
	char *env_cpy, *catt;
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

		envir = _getenv("PATH");
		if (envir == NULL)
			perror("_getenv");
		env_cpy = (char *)malloc(sizeof(char) * 512);
		if (!env_cpy)
			perror("malloc");

		env_cpy = _strcpy(env_cpy, envir);

		printf("%s\n", env_cpy);

		token = _strtok(env_cpy, ":");
		
		while (token != NULL)
		{
			catt = _strcat(token, c_cpy);
			printf("%s\n", catt);
			token = _strtok(NULL, ":");
		}
		
		free(c_cpy);
		free(env_cpy);
	}
	return 0;
}
