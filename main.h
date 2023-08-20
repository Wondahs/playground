#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

// Helper function prototypes from helpers.c
void write_char(char c);
void write_string(const char *s);
void print_integer(long num, char *buffer, int width, bool left_aligned, int precision, bool zero_padding);
void print_unsigned_long(unsigned long num, char *buffer, int width, bool left_aligned, int precision, bool zero_padding);
void print_octal_long(unsigned long num, char *buffer, int width, bool left_aligned, int precision, bool zero_padding);
void print_hex_long(unsigned long num, char *buffer, int width, bool left_aligned, int precision, bool uppercase, bool zero_padding);
void print_pointer(void *ptr, char *buffer, int width, bool left_aligned, int precision, bool zero_padding);
void print_non_printable_string(const char *s, char *buffer, int width, bool left_aligned, int precision);
void print_reversed_string(const char *s, char *buffer);
void print_rot13_string(const char *s, char *buffer);

// Format parser function prototypes from format_parser.c
const char *parse_flags(const char *format, int *flags);
const char *parse_length_modifier(const char *format, int *length_modifier);
const char *parse_field_width(const char *format, int *field_width);
const char *parse_precision(const char *format, int *precision);

// Format handlers function prototypes from format_handlers.c
typedef void (*print_function)(va_list args, char *buffer, int width, bool left_aligned, int precision, bool zero_padding);
void initialize_format_handlers();
print_function get_format_handler(char specifier);

// Custom printf function from _printf.c
int _printf(const char *format, ...);

#endif /* MAIN_H */

