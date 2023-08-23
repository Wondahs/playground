#include "main.h"

/**
 * handlePointer - Handles pointer specifier
 * @args: Args
 * @pchar: Pointer to number of characters printed
 */
void handlePointer(va_list args, int *pchar)
{
	void *ptr = va_arg(args, void *);
	char buffer[20];
	unsigned long address = (unsigned long)ptr;
	int num_digits = 0;
	int i, digit;

	while (address > 0)
	{
	address /= 16;
	num_digits++;
	}

	address = (unsigned long)ptr;
	for (i = num_digits - 1; i >= 0; i--)
	{
	digit = (address >> (i * 4)) & 0xF;
	buffer[num_digits - 1 - i] = (digit < 10) ? ('0' + digit) :
	('a' + digit - 10);
	}
	buffer[num_digits] = '\0';

	write(1, "0x", 2);
	write(1, buffer, num_digits);
	*pchar += num_digits + 2;
}


/**
 * handleCustomString - Handles custom syring
 * @args: Args
 * @pchar: Num of printed characters
 *
 */
void handleCustomString(va_list args, int *pchar)
{
	char *str = va_arg(args, char *);
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
	if (str[i] < 32 || str[i] >= 127)
	{
		/* Print non-printable character as \xXX (uppercase hexadecimal)*/

		write(1, "\\x", 2);
		if (str[i] < 16)
		{
			write(1, "0", 1);
			*pchar += 1;
		}
		print_hex((unsigned int)str[i], 1);
		*pchar += 4;
	}
	else
	{
		write(1, &str[i], 1);
		(*pchar)++;
	}
	}
}


/**
 * handleBinary - Handles printing of unsigned int in binary format
 * @args: Args
 * @pchar: Pointer to number of characters printed
 *
 * Return: Nothing
 */
void handleBinary(va_list args, int *pchar)
{
	unsigned int num = va_arg(args, unsigned int);

	char binaryBuffer[32];
	int j, i = 0;

	if (num == 0)
	{
	binaryBuffer[i++] = '0';
	}
	else
	{
		while (num > 0)
		{
			binaryBuffer[i++] = (num & 1) + '0';
			num >>= 1;
		}
	}

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &binaryBuffer[j], 1);
		(*pchar)++;
	}
}

/**
 * handleUnsigned - Handles unsigned int
 * @args: Args
 * @pchar: pointer to number of printed characters
 *
 */
void handleUnsigned(va_list args, int *pchar)
{
	unsigned int num = va_arg(args, unsigned int);
	*pchar += print_unsignedInt(num);
}

/**
 * handleOctal - Handles octals
 * @args: Args
 * @pchar: pointer to number of printed characters
 *
 */
void handleOctal(va_list args, int *pchar)
{
	unsigned int num = va_arg(args, unsigned int);
	*pchar += print_octal(num);
}
