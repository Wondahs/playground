#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024  // Adjust this size as needed

/**
 * struct formatHandler - For format specifier
 * @specifier: The format specifier character
 * @handler: Pointer to the handler function for the specifier
 */
struct formatHandler
{
	char specifier;
	void (*handler)(va_list, char *buffer, int *pchar);
};

typedef struct formatHandler FormatHandlerInfo;

/* int print_int(int num); 
int print_str(char *s); */

int print_int(int num, char *buffer, int *pchar);
int print_str(char *str, char *buffer, int *pchar);
int _printf(const char *format, ...);

void handleChar(va_list args, char *buffer, int *pchar);
void handleString(va_list args, char *buffer, int *pchar);
void handleInt(va_list args, char *buffer, int *pchar);

extern FormatHandlerInfo formatHandlers[];

int formatLoop(const char *format, va_list args, char *buffer, int *pchar);

void flushBuffer(char *buffer, int *pchar);

int _strlen(char *str);

#endif

