#include "main.h"

void handleChar(va_list args, char *buffer, int *pchar)
{
	char c = va_arg(args, int);

	buffer[(*pchar)++] = c;
}

void handleString(va_list args, char *buffer, int *pchar)
{
	char *str = va_arg(args, char *);

	*pchar += print_str(str, buffer, pchar);
}

void handleInt(va_list args, char *buffer, int *pchar)
{
	int num = va_arg(args, int);

	*pchar += print_int(num, buffer, pchar);
}

