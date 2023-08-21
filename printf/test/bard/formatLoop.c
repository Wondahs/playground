#include "main.h"

int formatLoop(const char *format, va_list args, char *buffer, int *pchar)
{
	FormatHandlerInfo formatHandlers[] = {
		{'c', handleChar}, {'s', handleString}, {'d', handleInt}, {'i', handleInt}};
	void (*handler)(va_list, char *, int *) = NULL;
	long unsigned int i;
	int ret = *pchar;
	int printed = 0;

	while (*format)
	{
		if (*format != '%')
		{
			buffer[(*pchar)++] = *format;
			printed = 1;
		}
		else
		{
			format++;
			for (i = 0; i < sizeof(formatHandlers) / sizeof(formatHandlers[0]); i++)
			{
				if (*format == formatHandlers[i].specifier)
				{
					handler = formatHandlers[i].handler;
					break;
				}
			}
			if (handler)
			{
				handler(args, buffer, pchar);
				if (buffer[(*pchar) - 1] == '\n')
				{
					flushBuffer(buffer, pchar);
				}
			}
			else
			{
				buffer[(*pchar)++] = *format;
				printed = 0;
			}
		}
		format++;
	}
	if (printed)
	{
		flushBuffer(buffer, pchar);
	}
	return (ret += *pchar);
}
