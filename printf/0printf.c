#include "main.h"

/**
*
*
*
*
*/
int _printf(const char *format, ...)
{
	int pchar = 0;
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			pchar++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case '%':
				{
					write(1, format, 1);
					pchar++;
					break;
				}
				case 'c':
				{
					char c = va_arg(args, int);

					write(1, &c, 1);
					pchar++;
					break;
				}
				case 's':
				{
					char *str = va_arg(args, char *);

					pchar += print_str(str);
					break;
				}
				default:
				{
					write(1, format, 1);
					pchar++;
				}
			}
		}
		format++;
	}
	va_end(args);

	return (pchar);	
}
