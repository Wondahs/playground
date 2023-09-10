#include "main.h"

/**
 *call_exec - Checks if command exists and calls execve
 *@tok_count: Number of tokens in command
 *@args: Pointer to pointer of arrays containing command and options
 *@cmd_count: Number of commands carried out
 *@arg: Name of shell program(Contained at argv[0])
 *
 *Return: Nothing
 */
void call_exec(int tok_count, char *args[], int cmd_count, char *arg)
{
	char *fullPath;
	int j;
	/* Check if command exixts */
		fullPath = checkPath(args[0]);
		if (fullPath == NULL)
		{
			_printf("%s: %i: %s: not found\n", arg, cmd_count, args[0]);
		/* Free allocated memory */
			for (j = 0; j < tok_count; j++)
			{
				free(args[j]);
				args[j] = NULL;
			}
			free(fullPath);
		}
		else
		{
			free(args[0]);
			args[0] = fullPath;
			execute(args);
		}
}
