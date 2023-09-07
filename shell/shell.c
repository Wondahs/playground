#include "main.h"

int main(void)
{
	char *c = NULL;
	int j, n = 10;
	ssize_t i;

	printf("$ Enter Name: ");
	fflush(stdout);

	i = _getline(&c, &n, STDIN_FILENO);
	c[i - 1] = '\0';
	j = _strlen(c);
	printf("%s is %i characters. Total printed is %lu with buffer %i\n", c, j, i, n);

	return 0;
}
