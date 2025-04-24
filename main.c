#include "shell.h"

/**
 * main - Entry point for simple shell
 * @ac: Argument count (unused)
 * @av: Argument vector
 *
 * Return: Exit status of last command in non-interactive mode, 0 otherwise
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int status = 0;

	(void)ac;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		status = execute_command(line, av[0]);
		if (status == -1)
		  {
		    free(line);
		    break;
		  }
		free(line);
		line = NULL;
	}

	return (status);
}
