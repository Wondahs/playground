#include "main.h"

/**
 * _getline - Read a line from a file descriptor and dynamically resize the buffer.
 * @lineptr: A pointer to a buffer where the line will be stored.
 * @n: A pointer to the size of the buffer.
 * @fd: The file descriptor from which to read the line.
 *
 * This function reads characters
 * from the given file descriptor until a newline
 * character is encountered or the end of the file is reached.
 * It dynamically resizes the buffer as needed to accommodate longer lines.
 * The line is stored in the 'lineptr'
 * buffer, and the 'n' pointer is updated with the new buffer size.
 *
 * Return: The number of characters read, or -1 on error.
 */
ssize_t _getline(char **lineptr, int *n, int fd)
{
	char ch;
	ssize_t capacity = *n, i = 0, bytesRead = read(fd, ch, 1);

	/* Check if lineptr and n are valid */
	if (!lineptr || !n)
		return (-1);

	if (*lineptr == NULL || capacity < 2)
	{
		capacity = 64;
		*lineptr = (char *)malloc(capacity);
		if (!(*lineptr))
			return (-1);
	}
	while (bytesRead == 1)
	{
		char *temp;

		if (i >= capacity - 2)
		{
			capacity *= 2;
			temp = (char *)malloc(capacity);
			if (!temp)
				return (-1);
			for (j = 0; j < i; j++)
				temp[j] = (*lineptr)[j];
			free(*lineptr);
			*lineptr = temp;
			i = j;
			free(temp);
			*n = capacity;
		}
		(*lineptr)[i++] = ch;
		if (ch == '\n')
			break;
	}
	if (i == 0 && bytesRead < 0)
		return (-1);
	(*lineptr)[i] = '\0';
	return (i);
}