// helpers.c

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include "main.h"

// Helper function to write a single character to the standard output
void write_char(char c)
{
	write(1, &c, 1);
}

// Helper function to write a string to the standard output
void write_string(const char *s)
{
	write(1, s, strlen(s));
}

// Print a formatted integer to the buffer
void print_integer(long num, char *buffer, int width, bool left_aligned, int precision, bool zero_padding)
{
	int printed = 0;
	bool is_negative = false;

	if (num < 0) {
		is_negative = true;
		num = -num;
		buffer[printed++] = '-';
	}

	// Convert the integer to a string in reverse order
	do {
		buffer[printed++] = '0' + (num % 10);
		num /= 10;
	} while (num > 0);

	// Add zero-padding if required
	if (zero_padding && width > printed) {
		while (printed < width) {
			buffer[printed++] = '0';
		}
	}

	// Add spaces for left alignment
	if (left_aligned && width > printed) {
		while (printed < width) {
			buffer[printed++] = ' ';
		}
	}

	// Reverse the string in the buffer
	for (int i = 0, j = printed - 1; i < j; i++, j--) {
		char temp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = temp;
	}

	// Write the formatted integer to standard output
	write_string(buffer);
}

// Print a formatted unsigned long to the buffer
void print_unsigned_long(unsigned long num, char *buffer, int width, bool left_aligned, int precision, bool zero_padding)
{
	int printed = 0;

	// Convert the unsigned long to a string in reverse order
	do {
		buffer[printed++] = '0' + (num % 10);
		num /= 10;
	} while (num > 0);

	// Add zero-padding if required
	if (zero_padding && width > printed) {
		while (printed < width) {
			buffer[printed++] = '0';
		}
	}

	// Add spaces for left alignment
	if (left_aligned && width > printed) {
		while (printed < width) {
			buffer[printed++] = ' ';
		}
	}

	// Reverse the string in the buffer
	for (int i = 0, j = printed - 1; i < j; i++, j--) {
		char temp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = temp;
	}

	// Write the formatted unsigned long to standard output
	write_string(buffer);
}

// Print a formatted octal long to the buffer
void print_octal_long(unsigned long num, char *buffer, int width, bool left_aligned, int precision, bool zero_padding)
{
	int printed = 0;

	// Convert the octal long to a string in reverse order
	do {
		buffer[printed++] = '0' + (num % 8);
		num /= 8;
	} while (num > 0);

	// Add zero-padding if required
	if (zero_padding && width > printed) {
		while (printed < width) {
			buffer[printed++] = '0';
		}
	}

	// Add spaces for left alignment
	if (left_aligned && width > printed) {
		while (printed < width) {
			buffer[printed++] = ' ';
		}
	}

	// Reverse the string in the buffer
	for (int i = 0, j = printed - 1; i < j; i++, j--) {
		char temp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = temp;
	}

	// Write the formatted octal long to standard output
	write_string(buffer);
}

// Print a formatted hexadecimal long to the buffer
void print_hex_long(unsigned long num, char *buffer, int width, bool left_aligned, int precision, bool uppercase, bool zero_padding)
{
	int printed = 0;
	const char hex_digits_uppercase[] = "0123456789ABCDEF";
	const char hex_digits_lowercase[] = "0123456789abcdef";
	const char *hex_digits = (uppercase ? hex_digits_uppercase : hex_digits_lowercase);

	// Convert the hexadecimal long to a string in reverse order
	do {
		buffer[printed++] = hex_digits[num % 16];
		num /= 16;
	} while (num > 0);

	// Add zero-padding if required
	if (zero_padding && width > printed) {
		while (printed < width) {
			buffer[printed++] = '0';
		}
	}

	// Add spaces for left alignment
	if (left_aligned && width > printed) {
		while (printed < width) {
			buffer[printed++] = ' ';
		}
	}

	// Reverse the string in the buffer
	for (int i = 0, j = printed - 1; i < j; i++, j--) {
		char temp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = temp;
	}

	// Write the formatted hexadecimal long to standard output
	write_string(buffer);
}

// Print a formatted pointer to the buffer
void print_pointer(void *ptr, char *buffer, int width, bool left_aligned, int precision, bool zero_padding)
{
	unsigned long num = (unsigned long)ptr;
	int printed = 0;
	const char hex_digits[] = "0123456789abcdef";

	// Convert the pointer to a hexadecimal string in reverse order
	do {
		buffer[printed++] = hex_digits[num % 16];
		num /= 16;
	} while (num > 0);

	// Add zero-padding if required
	if (zero_padding && width > printed) {
		while (printed < width) {
			buffer[printed++] = '0';
		}
	}

	// Add spaces for left alignment
	if (left_aligned && width > printed) {
		while (printed < width) {
			buffer[printed++] = ' ';
		}
	}

	// Add "0x" prefix
	buffer[printed++] = 'x';
	buffer[printed++] = '0';

	// Reverse the string in the buffer
	for (int i = 0, j = printed - 1; i < j; i++, j--) {
		char temp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = temp;
	}

	// Write the formatted pointer to standard output
	write_string(buffer);
}

// Print non-printable characters in a string to the buffer
void print_non_printable_string(const char *s, char *buffer, int width, bool left_aligned, int precision)
{
	int printed = 0;

	for (const char *ptr = s; *ptr != '\0'; ptr++) {
		if (*ptr < 32 || *ptr >= 127) {
			printed += sprintf(buffer + printed, "\\x%02X", (unsigned char)*ptr);
		} else {
			buffer[printed++] = *ptr;
		}
	}

	// Add spaces for left alignment
	if (left_aligned && width > printed) {
		while (printed < width) {
			buffer[printed++] = ' ';
		}
	}

	// Write the formatted non-printable string to standard output
	write_string(buffer);
}

// Print a reversed string to the buffer
void print_reversed_string(const char *s, char *buffer)
{
	int length = strlen(s);
	for (int i = 0; i < length; i++) {
		buffer[i] = s[length - i - 1];
	}
	buffer[length] = '\0';

	// Write the reversed string to standard output
	write_string(buffer);
}

// Print a ROT13'ed string to the buffer
void print_rot13_string(const char *s, char *buffer)
{
	int length = strlen(s);
	for (int i = 0; i < length; i++) {
		char c = s[i];
		if ('a' <= c && c <= 'z') {
			c = (c - 'a' + 13) % 26 + 'a';
		} else if ('A' <= c && c <= 'Z') {
			c = (c - 'A' + 13) % 26 + 'A';
		}
		buffer[i] = c;
	}
	buffer[length] = '\0';

	// Write the ROT13'ed string to standard output
	write_string(buffer);
}

