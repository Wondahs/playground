#include "printf.h"
#include <stdio.h>

int main(void)
{
	int num = 42;
	char str[] = "Hello, world!";

	int printed_chars = _printf("Number: %d\nString: %s\n", num, str);
	printf("Total characters printed: %d\n", printed_chars);
	return (0);
}
