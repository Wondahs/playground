#include "main.h"

void handleChar(va_list args, char *buffer, int *pchar)
{
    char c = va_arg(args, int);

    if (*pchar < BUFFER_SIZE - 1)
    {
        buffer[(*pchar)++] = c;
    }
    else
    {
        flushBuffer(buffer, pchar);
        buffer[(*pchar)++] = c;
    }
}

/**
 * handleString - Handles printing of string
 * @args: Args
 * @buffer: Buffer to store the output
 * @pchar: Pointer to number of characters printed
 */
void handleString(va_list args, char *buffer, int *pchar)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		*pchar = -1; // Set pchar to -1 to indicate an error
		return;
	}

	*pchar += print_str(str, buffer, pchar);
}

/* void handleString(va_list args, char *buffer, int *pchar)
{
    char *str = va_arg(args, char *);

    *pchar += print_str(str, buffer, pchar);
} */

void handleInt(va_list args, char *buffer, int *pchar)
{
    int num = va_arg(args, int);

    *pchar += print_int(num, buffer, pchar);
}
