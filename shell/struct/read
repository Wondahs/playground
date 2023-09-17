#include "main.h"

int errors(int n, const char *c);

/**
 *main - Entry point
 *@argc: Argument count
 *@argv: Pointer to arguments
 *
 *
 *Return: 0 if successful, 97 if wrong number of commands given,
 *98 if source file cant be read or opened
 *99 is target file cant be opened or written
 *100 if file cant be closed
 */
int main(int argc, char *argv[])
{
	int fileTo, fileFrom;
	char buffer[1024];
	ssize_t bytesRead, written;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	if (argv[1] == NULL)
		errors(98, argv[1]);
	if (argv[2] == NULL)
		errors(99, argv[2]);

	fileFrom = open(argv[1], O_RDONLY);
	if (fileFrom == -1)
		errors(98, argv[1]);

	fileTo = open(argv[2], O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (fileTo == -1)
		errors(99, argv[2]);

	while (1)
	{
		bytesRead = read(fileFrom, buffer, sizeof(buffer));
		if (bytesRead == 0)
			break;
		if (bytesRead == -1 || fileFrom == -1)
			errors(98, argv[1]);
		written = write(fileTo, buffer, bytesRead);
		if (written == -1 || fileTo == -1)
			errors(99, argv[2]);
	}
	if (close(fileFrom) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileFrom);
		exit(100);
	}
	if (close(fileTo) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileTo);
		exit(100);
	}
	return (0);
}


/**
 *errors - Handles errors
 *@n: error code
 *@c: filename
 *
 *
 *Return: Resoective errors
 */
int errors(int n, const char *c)
{
	switch (n)
	{
		case 98:
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", c);
			exit(98);
			break;
		}

		case 99:
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", c);
			exit(99);
			break;
		}
	}
	return (0);
}
