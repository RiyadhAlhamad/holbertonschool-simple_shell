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

		if (custom_getline(&line, &len, stdin) == -1)
			break;

		execute_command(line, av[0]);
		
		free(line);
		line = NULL;
	}
	return (0);
}
