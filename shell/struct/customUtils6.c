#include "main.h"

/**
 *looper - Handles command execution.
 *@cmmds: Struct holding information of commands separated by ";"
 *@args: Struct holding information of commands.
 *@argv_0: Name of program held in argv[0].
 *@cmd_count: Pointer to number of commands executed.
 *
 *Return: Nothing.
 */
void looper(cmd_t *cmmds, cmd_t *args, char *argv_0, int *cmd_count)
{
	int i;
	bool Path = true;

	for (i = 0; i < cmmds->arg_count; i++)
	{
		cmmds->args[i] = rmv_space(cmmds->args[i]);
		args->arg_count = tokenize_cmd(cmmds->args[i], args->args, " ");
		if (_strncmp("exit", args->args[0], _strlen(args->args[0])) == 0)
		{
			_ext(cmmds, args, *cmd_count, i, argv_0, Path);
			(*cmd_count)++;
			continue;
		}
		cl_exec(args, *cmd_count, argv_0, Path);
		free(cmmds->args[i]);
		(*cmd_count)++;
	}
}

/**
 * init_cmd_t - Initializes cmd_t struct.
 *
 * This function initializes a cmd_t object that will be uses in main program.
 *
 * Return: Initialized cmd_t object
 */
cmd_t *init_cmd_t()
{
	cmd_t *cmmds;

	cmmds = (cmd_t *)malloc(sizeof(cmd_t));
	if (!cmmds)
		perror("malloc - cmmds");
	cmmds->arg_count = 0;
	return (cmmds);
}

/**
 *read_file - Reads file.
 *@input_file: Name of file.
 *
 *
 *
 *Return: Copy of buffer containing file content
 */
char *read_file(char *input_file)
{
	int file;
	char buff[1024];
	ssize_t bytesRead, tBytesRead = 0;

	if (input_file == NULL)
	{
		_printf("%s is null", input_file);
		exit(97);
	}

	file = open(input_file, O_RDONLY);
	if (file == -1)
	{
		_printf("Error opening %s", input_file);
		exit(98);
	}
	buff[0] = '\0';
	while (1)
	{
		bytesRead = read(file, buff, sizeof(buff));
		tBytesRead += bytesRead;
		if (bytesRead == 0)
			break;
		if (bytesRead == -1 || file == -1)
		{
			_printf("Error reading %s", input_file);
			exit(99);
		}
	}
	buff[tBytesRead] = '\0';
	if (close(file) == -1)
	{
		_printf("Error closing %s", input_file);
		exit(100);
	}
	return (_strdup(buff));
}

/**
 *replace_char - Replaces character in a string.
 *@str: Input string.
 *@c: Character to replace.
 *@s: Character to replace @c.
 *
 *Return: Pointer to corrected string.
 */
char *replace_char(char *str, char c, char s)
{
	int i, j = 0;
	char *new_str;

	if (!str || str == NULL)
		return (NULL);

	new_str = malloc(_strlen(str) + 1);
	if (!new_str)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
			str[i] = s;
		new_str[j++] = str[i];
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

/**
 *rmv_double - Removes occurrence of double character @c in input string @cmd.
 *@cmd: Input string.
 *@c: Double character to remove
 *
 *
 *
 *Return: Pointer to corrected string.
 */
char *rmv_double(char *cmd, char c)
{
	int i, j = 0;
	char *cmd_clean;
	bool prev_space = (cmd[0] == c);

	cmd_clean = malloc(_strlen(cmd) + 1);

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == c)
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
