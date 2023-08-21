#include "main.h"

/**
 *_printf - Simplified implementation of printf
 *@format: Input string
 *@...: Variable number of string formatters
 *
 *Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int pchar = 0;
	int printed;
	
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	char buffer[BUFFER_SIZE];
	printed = formatLoop(format, args, &pchar);
	va_end(args);
	return (printed);
}
