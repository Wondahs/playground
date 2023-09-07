#include "main.h"

int main(void)
{
	char *c = NULL;
	int n = 10;
	ssize_t i;

	printf("$ ");
	i = _getline(&c, &n, STDIN_FILENO);

	printf("%s is %lu characters. with buffer %i\n", c, i, n);

	return 0;
}
