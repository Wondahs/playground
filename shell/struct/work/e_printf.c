#include "eprintf.h"

/**
 * e_printf - Custom printf for printing to STDERR_FILENO
 * @format: Input string
 *
 * This custom printf function only handles char, char * and int types and prints to STDERR.
 *
 * Return: Number of characters printed
 */
int e_printf(const char *format, ...)
{
	va_list args;
	const char *p = format;
	int char_count = 0;

	va_start(args, format);
	econdition(p, args, &char_count);
	va_end(args);
	return (char_count);
}
