// _printf.c

#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    char buffer[1024];
    int flags, width, length_modifier, precision;

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Move past '%'

            flags = 0;
            format = parse_flags(format, &flags);

            width = 0;
            format = parse_field_width(format, &width);

            length_modifier = 0;
            format = parse_length_modifier(format, &length_modifier);

            precision = -1;
            format = parse_precision(format, &precision);

            print_function func = get_format_handler(*format);
            if (func)
            {
                func(args, buffer, width, (flags & 0x08), precision, (flags & 0x01));
                count += strlen(buffer);
            }
            else
            {
                write(1, "%", 1);
                count++;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

