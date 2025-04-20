#include "shell.h"

/**
 * main - Entry point of the simple shell
 * Description:
 * Displays a prompt and waits for user input.
 * Accepts a single-word command without arguments.
 * Executes the command using execve.
 * Handles errors and EOF (Ctrl+D).
 * Returns: Always 0
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int status;
	char *argv[2];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			break;
		}

		/* Remove newline character */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		/* Skip empty input */
		if (line[0] == '\0')
			continue;

		argv[0] = line;
		argv[1] = NULL;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(line);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}

	free(line);
	return (0);
}
