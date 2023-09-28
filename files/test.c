#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>

char *rmv_spaces(char *dest, char *str)
{
	int len = strlen(str);
	int i;

	if (len < 0)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		if (str[i] == ' ')
			continue;
		dest[i] = str[i];
	}
	return (dest);
}
