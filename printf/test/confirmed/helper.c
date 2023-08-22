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
	int abs_num, i;
	int num_digits = 0;

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

		abs_num = num;
		/* int num_digits = 0; */

		while (abs_num > 0)
		{
			abs_num /= 10;
			num_digits++;
		}

		abs_num = num;
		for (i = num_digits - 1; i >= 0; i--)
		{
			buffer[len + i] = '0' + (abs_num % 10);
			abs_num /= 10;
		}

		len += num_digits;
	}

	write(1, buffer, len);

	return (len);
}

/**
 * print_unsigned - Print an unsigned integer
 * @num: The unsigned integer to be printed
 *
 * Return: The number of characters printed
 */
int print_unsignedInt(unsigned int num)
{
	char buffer[12];
	int len = 0;
	unsigned int abs_num, i;
	int num_digits = 0;

	if (num == 0)
	{
		buffer[len++] = '0';
	}
	else
	{
		abs_num = num;
		while (abs_num > 0)
		{
			abs_num /= 10;
			num_digits++;
		}

		abs_num = num;
		for (i = num_digits; i > 0; i--)
		{
			buffer[len + i - 1] = '0' + (abs_num % 10);
			abs_num /= 10;
		}

		len += num_digits;
	}

	write(1, buffer, len);

	return (len);
}

/**
 * print_octal - Print an unsigned integer in octal format
 * @num: The unsigned integer to be printed
 *
 * Return: The number of characters printed
 */
int print_octal(unsigned int num)
{
	char buffer[12];
	int len = 0;
	unsigned int abs_num, i;
	int num_digits = 0;

	if (num == 0)
	{
		buffer[len++] = '0';
	}
	else
	{
		abs_num = num;
		while (abs_num > 0)
		{
			abs_num /= 8;
			num_digits++;
		}

		abs_num = num;
		for (i = num_digits; i > 0; i--)
		{
			buffer[len + i - 1] = '0' + (abs_num % 8);
			abs_num /= 8;
		}

		len += num_digits;
	}

	write(1, buffer, len);

	return (len);
}


/**
 * print_hex - Print an unsigned integer in hexadecimal format
 * @num: The unsigned integer to be printed
 * @uppercase: Use uppercase letters for hex digits (1) or not (0)
 *
 * Return: The number of characters printed
 */
int print_hex(unsigned int num, int uppercase)
{
	char buffer[12];
	int len = 0;
	unsigned int abs_num, i;
	int num_digits = 0;
	const char *hex_chars = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (num == 0)
	{
		buffer[len++] = '0';
	}
	else
	{
		abs_num = num;
		while (abs_num > 0)
		{
			abs_num /= 16;
			num_digits++;
		}

		abs_num = num;
		for (i = num_digits; i > 0; i--)
		{
			buffer[len + i - 1] = hex_chars[abs_num % 16];
			abs_num /= 16;
		}

		len += num_digits;
	}

	write(1, buffer, len);

	return (len);
}
