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
	buffer[num_digits - 1 - i] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
	}
	buffer[num_digits] = '\0';

	write(1, "0x", 2);
	write(1, buffer, num_digits);
	*pchar += num_digits + 2;
}


/**
 * handlePointer - Handles pointer specifier
 * @args: Args
 * @pchar: Pointer to number of printed characters
 */
/*void handlePointer(va_list args, int *pchar)
{
	void *ptr = va_arg(args, void *);
	int num_digits = 0;
	uintptr_t ptr_value = (uintptr_t)ptr;

	write(1, "0x", 2);
	*pchar += 2;

	while (ptr_value > 0)
	{
	ptr_value >>= 4;
	num_digits++;
	}

	print_hex((uintptr_t)ptr, 1);

	*pchar += num_digits;
}*/

/**
 * handlePointer - Handles pointer soecifier
 * @args: Args
 * @pchar: Number of printed char
 *
 */
/* void handlePointer(va_list args, int *pchar)
{
	void *ptr = va_arg(args, void *);

	write(1, "0x", 2);
	*pchar += 2;

	print_hex((uintptr_t)ptr, 1);

	*pchar += 8;

}*/

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

#include "main.h"

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

	if (num == 0) {
	binaryBuffer[i++] = '0';
	} else {
	while (num > 0) {
		binaryBuffer[i++] = (num & 1) + '0';
		num >>= 1;
	}
	}

	for (j = i - 1; j >= 0; j--) {
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
	*pchar += print_unsigned(num);
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

/**
 * handleHexLower - Handles lowercase hex
 * @args: Args
 * @pchar: pointer to number of printed characters
 *
 */
void handleHexLower(va_list args, int *pchar)
{
	unsigned int num = va_arg(args, unsigned int);
	*pchar += print_hex(num, 0);
}

/**
 * handleHexUpper - Handles uppercase hex
 * @args: Args
 * @pchar: pointer to number of printed characters
 *
 */
void handleHexUpper(va_list args, int *pchar)
{
	unsigned int num = va_arg(args, unsigned int);
	*pchar += print_hex(num, 1);
}


