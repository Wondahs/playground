#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>  // Include this for strlen()

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024  // Adjust this size as needed

// Define struct formatHandler and typedef
struct formatHandler
{
    char specifier;
    void (*handler)(va_list args, char *buffer, int *pchar);
};
typedef struct formatHandler FormatHandlerInfo;

// Declare the print_int and print_str functions
int print_int(int num, char *buffer, int *pchar);
int print_str(char *str, char *buffer, int *pchar);

// Declare the _printf function
int _printf(const char *format, ...);

// Declare the handleChar, handleString, and handleInt functions
void handleChar(va_list args, char *buffer, int *pchar);
void handleString(va_list args, char *buffer, int *pchar);
void handleInt(va_list args, char *buffer, int *pchar);

// Declare the flushBuffer and formatLoop functions
void flushBuffer(char *buffer, int *pchar);
int formatLoop(const char *format, va_list args, char *buffer, int *pchar);

// Define HANDLERS macro to initialize formatHandlers array
#define HANDLERS \
    { {'c', handleChar}, {'s', handleString}, {'d', handleInt}, {'i', handleInt} }

// Define the formatHandlers array
extern FormatHandlerInfo formatHandlers[];

int _strlen(const char *str);

#endif

