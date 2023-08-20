#include "main.h"

/**
*
*
*
*/
int print_str(char *str)
{
	int i;
	int len = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		len++;
	}

	write(1, str, len);
	return (len);
}