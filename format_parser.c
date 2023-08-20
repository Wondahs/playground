// format_parser.c

#include <stdbool.h>
#include "main.h"

// Parse flags from the format specifier
const char *parse_flags(const char *format, int *flags)
{
    int parsed_flags = 0;
    bool done = false;

    while (!done)
    {
        switch (*format)
        {
            case '+':
                parsed_flags |= 0x01;
                break;
            case ' ':
                parsed_flags |= 0x02;
                break;
            case '#':
                parsed_flags |= 0x04;
                break;
            default:
                done = true;
                break;
        }
        if (!done)
        {
            format++;
        }
    }

    *flags = parsed_flags;
    return format;
}

// Parse length modifier from the format specifier
const char *parse_length_modifier(const char *format, int *length_modifier)
{
    int parsed_modifier = 0;
    bool done = false;

    while (!done)
    {
        switch (*format)
        {
            case 'l':
                parsed_modifier |= 0x01;
                break;
            case 'h':
                parsed_modifier |= 0x02;
                break;
            default:
                done = true;
                break;
        }
        if (!done)
        {
            format++;
        }
    }

    *length_modifier = parsed_modifier;
    return format;
}

// Parse field width from the format specifier
const char *parse_field_width(const char *format, int *field_width)
{
    int parsed_width = 0;
    while (*format >= '0' && *format <= '9')
    {
        parsed_width = parsed_width * 10 + (*format - '0');
        format++;
    }

    *field_width = parsed_width;
    return format;
}

// Parse precision from the format specifier
const char *parse_precision(const char *format, int *precision)
{
    int parsed_precision = 0;

    if (*format == '.')
    {
        format++;
        while (*format >= '0' && *format <= '9')
        {
            parsed_precision = parsed_precision * 10 + (*format - '0');
            format++;
        }
    }

    *precision = parsed_precision;
    return format;
}

