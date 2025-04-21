#include "shell.h"

/**
 * custom_getline - Read up to 1024 chars from STDIN_FILENO
 * @lineptr: Address of pointer to buffer
 * @n: Address of size of buffer
 * @stream: Unused, reading always from STDIN
 *
 * Return: Number of chars read, or -1 on EOF/error
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t bytes_read;
	char *buffer;

	(void)stream;

	buffer = malloc(1024);
	if (buffer == NULL)
		return (-1);

	bytes_read = read(STDIN_FILENO, buffer, 1024);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (-1);
	}

	buffer[bytes_read] = '\0';
	*lineptr = buffer;
	*n = bytes_read + 1;
	return (bytes_read);
}
