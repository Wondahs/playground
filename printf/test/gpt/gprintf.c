#include "main.h"

int _printf(const char *format, ...)
{
    int pchar = 0;
    int printed;
    va_list args;

    if (format == NULL)
        return (-1);
    va_start(args, format);
    char buffer[BUFFER_SIZE];
    printed = formatLoop(format, args, buffer, &pchar);  // Pass buffer as an argument
    va_end(args);
    return (printed);
}
