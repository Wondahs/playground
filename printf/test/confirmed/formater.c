#include "main.h"

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


