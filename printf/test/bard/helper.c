#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#include "main.h"

void flushBuffer(char *buffer, int *pchar)
{
	write(1, buffer, *pchar);
	*pchar = 0;
}

int print_str(char *str, char *buffer, int *pchar)
{
	int len = _strlen(str);

	if (*pchar + len >= BUFFER_SIZE)
	{
		flushBuffer(buffer, pchar);
	}

	for (int i = 0; i < len; i++)
	{
		buffer[(*pchar)++] = str[i];
	}

	return len;
}

int print_int(int num, char *buffer, int *pchar)
{
	char temp_buffer[12];  // Temporary buffer to hold integer characters
	int len = 0;
	int abs_num, i;
	int num_digits = 0;

	if (num == 0)
	{
		temp_buffer[len++] = '0';
	}
	else
	{
		if (num < 0)
		{
			buffer[(*pchar)++] = '-';
			num = -num;
		}

		abs_num = num;

		while (abs_num > 0)
		{
			temp_buffer[num_digits++] = '0' + (abs_num % 10);
			abs_num /= 10;
		}

		for (i = num_digits - 1; i >= 0; i--)
		{
			buffer[(*pchar)++] = temp_buffer[num_digits - 1 - i];
		}
	}

	return len;
}

int _strlen(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}

	return len;
}
