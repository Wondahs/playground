#include "main.h"

/**
 *
 *
 *
 *
 *
 */
int _setenv(char *variable, char *value)
{
	int j, i = 0;
	char **new_env;
	char *new_var;

	if (variable == NULL || value == NULL || !variable || !value)
		return (-1);
	new_var = malloc(_strlen(variable) + _strlen(value) + 2);
	if (!new_var)
		return (-1);
	new_var = _strcpy(new_var, variable);
	new_var = _strcat(new_var, "=");
	new_var = _strcat(new_var, value);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], variable, _strlen(variable) == 0))
		{
			free(environ[i]);
			environ[i] = new_var;
			return (0);
		}
	}
	j = 0;
	while (environ[j] != NULL)
		j++;
	new_env = (char **)malloc((j + 2) * sizeof(char *));
	if (!new_env)
		return (-1);
	for (i = 0; environ[i] != NULL; i++)
		new_env[i] = environ[i];
	free(environ);
	environ = new_env;
	environ[j++] = new_var;
	environ[j] = NULL;
	return (0);
}

/**
 *
 *
 *
 *
 *
 *
 *
 */
int _unsetenv(char *variable)
{
	int i, j = 0, k = 0;
	char **temp;

	if (variable == NULL || !variable)
		return (-1);
	/* Get total pointers in environ */
	while (environ[j] != NULL)
		j++;
	/* Allocate space for temporary pointer to pointers */
	temp = (char **)malloc(j * sizeof(char *));
	if (!temp)
		return (-1);
	/* Copy variables to temp, excluding specified variable */
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], variable, _strlen(variable) == 0))
			continue;
		temp[k++] = environ[i];
	}
	/* Null terminate temp, and point environ to temp */
	temp[k] = NULL;
	free(environ);
	environ = temp;
	return (0);
}

/**
 *
 *
 *
 *
 *
 */
bool sCases(cmd_t *cmmds, cmd_t *args, int cmd_count, char argv_0, bool Path)
{
	int condition = 0;

	if (_strncmp("setenv", args->args[0], _strlen(args->args[0])) == 0)
		{
			condition = _setenv(args->args[1], args->args[2]);
			if (condition == -1)
				perror("setenv");
			return (true);
		}
	if (_strncmp("unsetenv", args->args[0], _strlen(args->args[0])) == 0)
		{
			condition = _unsetenv(args->args[1]);
			if (condition == -1)
				perror("unsetenv");
			return (true);
		}
	if (_strncmp("exit", args->args[0], _strlen(args->args[0])) == 0)
		{
			_ext(cmmds, args, *cmd_count, i, argv_0, Path);
			return (true);
		}
	return (false);
}
