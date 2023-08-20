// format_handlers.c

#include "main.h"

typedef void (*print_function)(va_list args, char *buffer, int width, bool left_aligned, int precision, bool zero_padding);

static print_function format_handlers[128] = {NULL};

void initialize_format_handlers()
{
    format_handlers['c'] = print_char;
    format_handlers['s'] = print_string;
    format_handlers['d'] = print_integer;
    format_handlers['i'] = print_integer;
    format_handlers['u'] = print_unsigned_long;
    format_handlers['o'] = print_octal_long;
    format_handlers['x'] = print_hex_long;
    format_handlers['X'] = print_hex_long;
    format_handlers['p'] = print_pointer;
    format_handlers['S'] = print_non_printable_string;
    format_handlers['r'] = print_reversed_string;
    format_handlers['R'] = print_rot13_string;
}

print_function get_format_handler(char specifier)
{
    initialize_format_handlers();
    return format_handlers[(int)specifier];
}

