#include "shell.h"

int main(int argc, char **argv, char **env)
{
	unsigned int i;
	char *prompt = "$ "

	i = 0;
	while(env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}

	return (0);
}