#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

#define UNUSED(x) (void)(x)


int print_int(int num);
int _printf(const char *format, ...);
int print_str(char *s);
/* void print_char(char *s); */

/**
 * struct formatHandler - For format specifier
 * @specifier: First member
 * @handler: Second member
 *
 */
struct formatHandler
{
	/* Struct for specifier handling*/
	char specifier;
	void (*handler)(va_list args, int *pchar);
};

/**
 * FormatHandlerInfo - Typedef for formatHandler
 */
typedef struct formatHandler FormatHandlerInfo;

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
    {'d', handleInt}, {'i', handleInt}, \
    {'b', handleBinary}, {'u', handleUnsigned}, \
    {'o', handleOctal}, {'x', handleHexLower}, \
    {'X', handleHexUpper}, {'S', handleCustomString}, \
    {'p', handlePointer}, {'r', handleReversedString}, \
    {'R', handleRot13String}}

/* New Functions */
void handleCustomString(va_list args, int *pchar);
void handlePointer(va_list args, int *pchar);
void handleReversedString(va_list args, int *pchar);
void handleRot13String(va_list args, int *pchar);
int print_unsignedInt(unsigned int num);
int print_octal(unsigned int num);
int print_hex(unsigned int num, int uppercase);
void handleUnsigned(va_list args, int *pchar);
void handleOctal(va_list args, int *pchar);
void handleHexLower(va_list args, int *pchar);
void handleHexUpper(va_list args, int *pchar);
void handleBinary(va_list args, int *pchar);

#endif
