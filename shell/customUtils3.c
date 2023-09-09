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
	char *token, *token_cpy, *full_path, *env_cpy = NULL;

	if (envir == NULL)
		perror("_getenv");
	/* Duplicate PATH*/
	env_cpy = _strdup(envir);

	/* Tokenize PATH */
	token = _strtok(env_cpy, ":");
	while (token != NULL)
	{
		/* Duplicate token and concatenate command to necessary PATHS*/
		token_cpy = malloc(_strlen(token) + _strlen(cmd) + 2);
		if (!token_cpy)
		{
			perror("malloc");
			return (NULL);
		}
		token_cpy = _strcpy(token_cpy, token);
		token_cpy = _strcat(token_cpy, "/");
		full_path = _strcat(token_cpy, cmd);
		/*printf("%s\n", full_path);*/
		if (access(full_path, X_OK) == 0)
		{
			free(env_cpy);
			env_cpy = NULL;
			return (full_path);
		}
		else
		{
			free(token_cpy);
			token_cpy = NULL;
			token = _strtok(NULL, ":");
		}
	}
	free(env_cpy);
	env_cpy = NULL;
	return (NULL);
}

/**
 *getPrompt - Prints '$' and receives command from user.
 *
 *This function receives command, and copies it into a string
 *without including the '\n' character. If command is 'exit' it returns NULL.
 *
 *Return: Pointer to a copy of the command.
 */
char *getPrompt(void)
{
	char *c_cpy;
	char *c = malloc(128);
	ssize_t i;
	int n = 20;

	/* Flush stdout and show prompt */
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);

	/* Get command */
	i = _getline(&c, &n, STDIN_FILENO);

	/* Set string terminator, duplicate command and return */
	c[i - 1] = '\0';
	c_cpy = _strdup(c);
	if (!c_cpy)
		perror("strdup error");
	/* Check for exit command */
	if (_strncmp("exit", c_cpy, _strlen(c_cpy)) == 0)
	{
		printf("exiting\n");
		free(c_cpy);
		free(c);
		return (NULL);
	}
	free(c);
	return (c_cpy);
}

/**
 *
 *
 *
 *
 *
 *
 */
void execute(char *args[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
		perror("fork failed");
	if (child_pid == 0)
	{
		execve(args[0], args, NULL);
		perror("execve failed");
	}
	else
	
		wait(&status);
	return;
}
