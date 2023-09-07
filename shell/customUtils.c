#include "main.h"

/**
 *
 *
 *
 *
 *
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int i;

	for (i = 0; environ[i] != NULL;i++)
	{
		char *variable = environ[i];

		if (_strncmp(variable, name, _strlen(name)) == 0)
		{
			char *value = _strchr(variable, '=');
			if (value != NULL)
				return (value + 1);
		}
	}
	return (NULL);
}

/**
 *
 *
 *
 *
 *
 */
int _strlen(const char *c)
{
	int len = 0;

	while (c[len] != '\0')
		len++;
	return (len);
}

/**
 *
 *
 *
 *
 *
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);
}

/**
 *
 *
 *
 *
 *
 *
 */
char *_strchr(char *s, char c)
{
	while (*s != NULL)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (1);
}
