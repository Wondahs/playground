#include "main.h"
/**
 *handleChar - Handles printing of char
 *@args: Args
 *@pchar: Pointer to number of characters printed
 *
 *Return: Nothing
 */
void handleChar(va_list args, int *pchar)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	(*pchar)++;
}

/**
 *handleString - Handles printing of string
 *@args: Args
 *@pchar: Pointer to number of characters printed
 *
 *Return: Nothing
 */
void handleString(va_list args, int *pchar)
{
	char *str = va_arg(args, char *);

	*pchar += print_str(str);
}

/**
 *handleInt - Handles printing of integer
 *@args: Args
 *@pchar: Pointer to number of characters printed
 *
 *Return: Nothing
 */
void handleInt(va_list args, int *pchar)
{
	int num = va_arg(args, int);

	*pchar += print_int(num);
}

/**
 * handleRot13String - Handles printing of a string in ROT13 encoding
 * @args: Args
 * @pchar: Pointer to number of characters printed
 *
 * Return: Nothing
 */
void handleRot13String(va_list args, int *pchar)
{
	char *str = va_arg(args, char *);
	int i;

	/* ROT13 transformation */
	for (i = 0; str[i] != '\0'; i++)
	{
	char c = str[i];

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		char base = (c >= 'a' && c <= 'z') ? 'a' : 'A';

		c = base + ((c - base + 13) % 26);
	}

	write(1, &c, 1);
	(*pchar)++;
	}
}

/**
 *handleReversedString - Handles custom format specifier r
 *@args: Args
 *@pchar: Pointer to nunber of printed chars
 *
 *
 */
void handleReversedString(va_list args, int *pchar)
{
	char *str = va_arg(args, char *);
	int length = 0;
	int i;

	if (str == NULL)
	{
		write(1, "%r", 2);
		*pchar += 2;
	}
	else
	{
	while (str[length] != '\0')
	{
	length++;
	}

	/* Print the reversed string */
	for (i = length - 1; i >= 0; i--)
	{
	write(1, &str[i], 1);
	(*pchar)++;
	}
	}
}
