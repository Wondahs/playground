#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define UNUSED(x) (void)(x)


int print_int(int num);
int _printf(const char *format, ...);
int print_str(char *s);
/* void print_char(char *s); */
typedef struct
{
	/* Struct for specifier handling*/
	char specifier;
	void (*handler)(va_list args, int *pchar);
} FormatHandlerInfo;

void handleChar(va_list args, int *pchar);
void handleString(va_list args, int *pchar);
void handleInt(va_list args, int *pchar);
extern FormatHandlerInfo formatHandlers[];
int formatLoop(const char *format, va_list args, int *pchar);
void handleSpecifier(const char **format, va_list args, int *pchar);
void handleNonSpecifier(const char **format, int *pchar);
FormatHandlerInfo findHandler(char specifier);

#define HANDLERS \
    {{'c', handleChar}, {'s', handleString}, \
	{'d', handleInt}, {'i', handleInt}}


#endif
