#include "main.h"

/**
 *checkPath - Checks if given command can be executed before fork and execve.
 *@cmd: Pointer to command
 *
 *This function takes the command, and checks through the
 *environment variable PATH to check if the command can be executed.
 *
 *Return: Full path of command, or NULL if the command is not in PATH.
 */
char *checkPath(char *cmd)
{
	/* Get environment variable PATH*/
	char *envir = _getenv("PATH");
	char *token, *token_cpy, *full_path, *env_cpy;

	if (envir == NULL)
		perror("_getenv");
	/* Duplicate PATH*/
	env_cpy = malloc(sizeof(char) * _strlen(envir) + 1);
	if (!env_cpy)
	{
		printf("Malloc failed");
		perror("malloc");
	}
	env_cpy = _strcpy(env_cpy, envir);

	/* Tokenize PATH */
	token = _strtok(env_cpy, ":");
	while (token != NULL)
	{
		/* Duplicate token and concatenate command to necessary PATHS*/
		token_cpy = malloc(_strlen(token) + 1);
		if (!token_cpy)
			perror("malloc");
		token_cpy = _strcpy(token_cpy, token);
		token_cpy = _strcat(token_cpy, "/");
		full_path = _strcat(token_cpy, cmd);
		/* printf("%s\n", full_path); */
		if (access(full_path, X_OK) == 0)
		{
			free(token_cpy);
			free(env_cpy);
			return (full_path);
		}
		token = _strtok(NULL, ":");
	}
	return (NULL);
}
