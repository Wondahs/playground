#include "main.h"

/**
 * cd - Change the current working directory.
 * @args: Pointer to the command arguments.
 * @argv_0: The name of the program.
 * @cmd_count: The command count.
 */
void cd(cmd_t *args, char *argv_0, int cmd_count)
{
	char *arg = args->args[1];
	char current_dir[1024];

	(void)cmd_count;
	(void)argv_0;
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("cd");
		return;
	}
	if (arg == NULL || _strncmp(arg, "~", 1) == 0 || _strncmp(arg, "$HOME", 5) == 0)
	{
		const char *home = _getenv("HOME");
		if (chdir(home) == -1)
		{
			perror("cd");
			return;
		}
	}
	else if (_strncmp(arg, "-", 1) == 0 || _strncmp(arg, "$OLDPWD", 7) == 0)
	{
		const char *oldpwd = _getenv("OLDPWD");
		if (chdir(oldpwd) == -1)
		{
			perror("cd");
			return;
		}
	}
	else
	{
		int len = _strlen(arg);
		if (arg[len - 1] != '/')
		{
			arg[len++] = '/';
			arg[len] = '\0';
		}

		if (chdir(arg) == -1)
		{
			perror("cd");
			return;
		}
	}
	_setenv("OLDPWD", current_dir);
	_setenv("PWD", getcwd(NULL, 0));
}

/**
 * _strdup - Duplicate a string.
 * @s: The string to duplicate.
 *
 * Return: A pointer to the newly allocated duplicate string.
 *         NULL if memory allocation fails or if `s` is NULL.
 */
char *free_strdup(char *s)
{
	int i, len;
	char *dup;
	if (s == NULL)
	{
		return (NULL);
	}

	len = _strlen(s);
	dup = malloc(len + 1);

	if (dup == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		dup[i] = s[i];
	}
	dup[len] = '\0';

	free(s);
	return (dup);
}

