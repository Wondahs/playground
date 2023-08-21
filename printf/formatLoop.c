#include "main.h"

/**
 * formatLoop - Handles formatting and printing
 * @format: The format string
 * @args: List of arguments
 * @pchar: Pointer to the character count
 */
int formatLoop(const char *format, va_list args, int *pchar)
{
	FormatHandlerInfo formatHandlers[] = {
		{'c', handleChar}, {'s', handleString}, {'d', handleInt}, {'i', handleInt}};
	void (*handler)(va_list, int *) = NULL;
	long unsigned int i;
	int ret = *pchar;

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			ret++;
		}
		else
		{
			format++;
			/*void (*handler)(va_list, int *) = NULL; */

			for (i = 0; i < sizeof(formatHandlers) / sizeof(formatHandlers[0]); i++)
			{
				if (*format == formatHandlers[i].specifier)
				{
					handler = formatHandlers[i].handler;
					break;
				}
			}
			if (handler)
				handler(args, pchar);
			else
			{
				write(1, format, 1);
				ret++;
			}
		}
		format++;
	}
	return (ret += *pchar);
}
