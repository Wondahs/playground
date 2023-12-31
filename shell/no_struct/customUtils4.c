#include "main.h"

/**
 *cl_exec - Checks if command exists and calls execve
 *@tok_count: Number of tokens in command
 *@args: Pointer to pointer of arrays containing command and options
 *@cmd_count: Number of commands carried out
 *@arg: Name of shell program(Contained at argv[0])
 *@Path: Boolean that tells if previous command is successful
 *Return: Nothing
 */
void cl_exec(int tok_count, char *args[], int cmd_count, char *arg, bool Path)
{
	char *fullPath;
	(void)Path;

	if (count_slash(args[0]))
		fullPath = abs_path(args[0]);
	else
		fullPath = checkPath(args[0]);
	if (fullPath == NULL)
	{
		Path = false;
		_printf("%s: %i: %s: not found\n", arg, cmd_count, args[0]);
		/* Free allocated memory */
		free_args(args, tok_count);
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
	int total = 0;

	len = _strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			total = (total << 1) + (total << 3);
			total += (str[i] - '0');
		}
		else
			return (-1);
	}
	return (total);
}

/**
 *sh_exit - Handles exit condition
 *@args: Array containing arguments
 *@i: Number of arguments in args
 *@cmd_count: Number of commands already passed to shell
 *@arg: Name of shell program
 *@Path: Boolean that tells if previous command was successful
 *
 *Return: Nothing
 */
void _ext(char *a[], int i, int cCt, int sc, char *arg, bool Path, char *s[])
{
	int exit_num;

	if (a[1] == NULL && Path == true)
	{
		free(s[sc]);
		free_args(a, i);
		exit(0);
	}
	else if (a[1] == NULL && Path == false)
	{
		free(s[sc]);
		free_args(a, i);
		exit(127);
	}

	exit_num = exit_atoi(a[1]);
	if (exit_num == -1)
	{
		_printf("%s: %i: %s: Illegal number:", arg, cCt, a[0]);
		_printf(" %s\n", a[1]);
		free(s[sc]);
		free_args(a, i);
	}
	else
	{
		free(s[sc]);
		free_args(a, i);
		exit(exit_num);
	}
}

/**
 * free_args - Frees argument vector
 * @args: Vector to free
 * @num_token: Number of tokens in vector
 *
 * Return: Nothing
 */
void free_args(char *args[], int num_token)
{
	int i;

	for (i = 0; i < num_token; i++)
	{
		free(args[i]);
		args[i] = NULL;
	}
}
