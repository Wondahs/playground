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
			Path = false;
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
			Path = true;
			free(args[0]);
			args[0] = fullPath;
			execute(args);
		}
}

/**
 *rmv_space - Removes unnecessary spaces from input string
 *@cmd: Input string
 *
 *Return: Corrected string
 */
char *rmv_space(char *cmd)
{
	int i, j = 0;
	char *cmd_clean;
	bool prev_space = (cmd[0] == ' ' || cmd[0] == '\t');

	cmd_clean = malloc(_strlen(cmd) + 1);

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == ' ' || cmd[i] == '\t')
		{
			if (!prev_space)
				cmd_clean[j++] = cmd[i];
			prev_space = true;
		}
		else
		{
			cmd_clean[j++] = cmd[i];
			prev_space = false;
		}
	}
	cmd_clean[j] = '\0';
	free(cmd);
	cmd = cmd_clean;
	return (cmd);
}

/**
 *exit_atoi - A string-to-integer converter for exit condition
 *@str: String to convert
 *
 *
 *Return: Integer if successful, -1 if non-numeric character found in input
 */
int exit_atoi(char *str)
{
	int i, len = 0;
	int ten = 1, total = 0;

	len = _strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			total += (str[i] - '0') * ten;
			ten *= 10;
		}
		else
			return (-1);
	}
	return (total);
}

/**
 *
 *
 *
 *
 */
int sh_exit(char *args[])
{
	int exit_num;

	exit_num = exit_atoi(args[1]);
	if (exit_num == -1)
		return -1;
	exit(exit_num);
}
