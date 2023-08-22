#include "main.h"

int formatLoop(const char *format, va_list args, char *buffer, int *pchar)
{
    FormatHandlerInfo formatHandlers[] = HANDLERS;
    void (*handler)(va_list, char *, int *) = NULL;
    long unsigned int i;
    int ret = *pchar;

    while (*format)
    {
        if (*format != '%')
        {
            buffer[(*pchar)++] = *format;
            ret++;  // Increment ret for each printed character
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
                if (*pchar >= BUFFER_SIZE)
                {
                    flushBuffer(buffer, pchar);
                }
            }
            else
            {
                buffer[(*pchar)++] = *format;
                ret++;  // Increment ret for the '%' character
            }
        }
        format++;
    }
    if (*pchar > 0)
    {
        flushBuffer(buffer, pchar);
    }
    return ret;  // Return the correct number of printed characters
}
