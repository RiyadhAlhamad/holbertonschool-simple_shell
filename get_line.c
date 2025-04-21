#include "shell.h"

/**
 * custom_getline - Custom implementation of getline function
 * @lineptr: Pointer to the line buffer
 * @n: Pointer to the size of the buffer
 * @stream: Input stream (not used, reads from STDIN)
 *
 * Return: Number of characters read, or -1 on failure
 */

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t nchars;
	char *buffer;

	(void)stream; /* stream is unused */

	if (lineptr == NULL || n == NULL)
		return (-1);

	buffer = malloc(1024);
	if (buffer == NULL)
		return (-1);

	nchars = read(STDIN_FILENO, buffer, 1024);
	if (nchars > 0)
	{
		buffer[nchars] = '\0';
		*lineptr = buffer;
		*n = 1024;
	}
	else
	{
		free(buffer);
		return (-1);
	}

	return (nchars);
}
