#include "main.h"
#include "printf.c"

int main(void)
{
    char *name = "Mike";
    char c = 'D';
    int age = 50, year = 2019, ch, ch2;

	ch = _printf("My%s, %c, %d, %i\n", name, c, age, year);
	//printf("%i\n", ch);
	//ch2 = printf("My%s, %c, %d, %i\n", name, c, age, year);
	_printf("%i\n", ch2);
    return 0;
}
