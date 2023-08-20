#include "main.h"

/**
 *print_str - Prints string
 *@str: Input string
 *
 *Return: Length of str
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


/**
 * print_int - Print an integer using %i or %d format
 * @num: The integer to be printed
 *
 * Return: The number of characters printed
 */
int print_int(int num)
{
	char buffer[12];
	int len = 0;

	if (num == 0)
	{
		buffer[len++] = '0';
	}
	else
	{
		if (num < 0)
		{
			buffer[len++] = '-';
			num = -num;
		}

		int abs_num = num;
		int num_digits = 0;

		while (abs_num > 0)
		{
			abs_num /= 10;
			num_digits++;
		}

		abs_num = num;
		for (int i = num_digits - 1; i >= 0; i--)
		{
			buffer[len + i] = '0' + (abs_num % 10);
			abs_num /= 10;
		}

		len += num_digits;
	}

	write(1, buffer, len);

	return (len);
}
