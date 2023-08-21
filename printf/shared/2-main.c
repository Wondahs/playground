#include <stdio.h>
#include <stdarg.h>
#include "2-main.h"

int main(void)
{
	int num = 42;
	char str[] = "Hello, world!";

	int printed_chars = my_printf("Number: %d\nString: %s\n", num, str);
	printf("Total characters printed: %d\n", printed_chars);
	return (0);
}
