#include "shell.h"

/**
 * main - Entry point of the simple shell program
 *
 * Return: Always 0
 */

int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	(void)ac;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		read = custom_getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (line[0] != '\n')
			execute_command(line, av[0]);
	}
	free(line);
	return (0);
}
