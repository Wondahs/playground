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
	int i = 0;
	static char new_var[4048];

	if (variable == NULL || value == NULL || !variable || !value)
		return (-1);

	new_var[0] = '\0';
	_strcpy(new_var, variable);
	_strcat(new_var, "=");
	_strcat(new_var, value);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], variable, _strlen(variable)) == 0)
		{
			environ[i] = new_var;
			return (0);
		}
	}
	for (i = 0; environ[i] != NULL; i++)
		i++;
	environ[i++] = new_var;
	environ[i] = NULL;
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
	int i = 0, size = 0, k = 0;
	char **temp;


	if (variable == NULL || !variable)
		return (-1);
	while (environ[size] != NULL)
		size++;
	temp = (char **)malloc((size + 2) * sizeof(char *));
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], variable, _strlen(variable)) != 0)
		
			temp[k++] = environ[i];
	}
	temp[k] = NULL;
	for (i = 0; i <= k; i++)
	{
		environ[i] = temp[i];
	}
	free(temp);
	return (0);
}

/**
 *
 *
 *
 *
 *
 */
bool sCases(cmd_t *cmmds, cmd_t *args, int cmd_count,
		int i, char *argv_0, bool Path)
{
	int condition = 0;

	if (_strncmp("setenv", args->args[0], _strlen(args->args[0])) == 0)
		{
			condition = _setenv(args->args[1], args->args[2]);
			if (condition == -1)
				perror("setenv");
			free_args(args->args, args->arg_count);
			return (true);
		}
	if (_strncmp("unsetenv", args->args[0], _strlen(args->args[0])) == 0)
		{
			condition = _unsetenv(args->args[1]);
			if (condition == -1)
				perror("unsetenv");
			free_args(args->args, args->arg_count);
			return (true);
		}
	if (_strncmp("exit", args->args[0], _strlen(args->args[0])) == 0)
		{
			_ext(cmmds, args, cmd_count, i, argv_0, Path);
			return (true);
		}
	return (false);
}

/**
 * copy_env - Copies environment variables
 *
 */
void copy_env(void)
{
	static char *new_env[1024];
	int size = 0, i;

	while (environ[size] != NULL)
		size++;

	for (i = 0; i < size; i++)
		new_env[i] = environ[i];
	environ = new_env;
	environ[i] = NULL;
}
