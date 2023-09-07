#include "main.h"

int main(void)
{
	char *prompt = "$ ";
	char cmd[] = "";
	
	printf("%s", prompt);
	scanf("%s", cmd);

	printf("%s\n", _strchr(cmd, 'P'));
	printf("%s\n", _getenv(cmd));
	
	return (0);
}
