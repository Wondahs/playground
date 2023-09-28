#include <stdio.h>
#include <stdlib.h>
int _unsetenv(char *variable);
int _setenv(char *variable, char *value);
int main (void)
{
	char variable[] = "MY";
	char variable2[] = "PWD";
	char value[] = "mine";
	int setenv = 0, unset = 0;

	setenv = _setenv(variable, value);
	if (setenv != 0)
		printf("Failed to set %s.\n", variable);
	else
		printf("Set successfully");
	unset = _unsetenv(variable);
	if (unset != 0)
		printf("Failed to unset %s.\n", variable2);
	else
		printf("unset successfully");
	return 0;
}

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
