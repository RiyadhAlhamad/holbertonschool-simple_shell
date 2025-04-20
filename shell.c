#include "shell.h"

/**
 * _shell - simple shell loop that executes commands without arguments
 *
 * Description: Displays a prompt, reads user input, and executes the
 * input as a command using execve. It handles basic errors and EOF (Ctrl+D).
 *
 * Return: 0 on success, or exit status on failure
 */
int _shell(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	char *argv[2];

	while (1)
	{
		printf("#cisfun$ ");
		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			printf("\n");
			break;
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		if (line[0] == '\0')
			continue;

		pid = fork();
		if (pid == 0)
		{
			argv[0] = line;
			argv[1] = NULL;

			if (execve(argv[0], argv, environ) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid > 0)
		{
			wait(NULL);
		}
		else
		{
			perror("fork");
			free(line);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	return (0);
}
