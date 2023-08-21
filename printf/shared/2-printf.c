#include <stdio.h>
#include <stdarg.h>
#include "2-main.h"

int my_printf(const char *format, ...)
{
	va_list args;
	const char *p = format;
	int char_count = 0;

	va_start(args, format);
	while (*p != '\0') {
		if (*p == '%') 
		{
			p++;
			switch (*p) {
				case 'c':
				{
					char_count = print_char(&char_count, *p);
					break;
				}
				case 's':
				{
					char *s = va_arg(args, char *);

					char_count += print_str(s);
					break;
				}
				case 'i':
				case 'd':
				{
					int num = va_arg(args, int);

					char_count += print_int(num);
					break;
				}
				case '%':
					char_count = print_percent(&char_count);
					break;
				default:
					char_count = print_char(&char_count, *p);
			}
		}
		else 
		{
			char_count = print_char(&char_count, *p);
		}
		p++;
	}

	va_end(args);
	return (char_count);
}
