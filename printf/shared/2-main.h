#ifndef MY_PRINTF_UTILS_H
#define MY_PRINTF_UTILS_H

#include <stdarg.h>


int my_printf(const char *format, ...);
int print_char(int *char_count, char c);
int print_string(int *char_count, const char *str);
int print_integer(int *char_count, int num);
int print_percent(int *char_count);
int print_int(int num);
int print_str(char *str);

#endif
