#include "shell.h"

/*
 * File: main.c
 * Description: Entry point for a simple shell.
 * Author: Riyadh Alhamad
 */

void execute_command(char *cmd);

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *cmd;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			free(line);
			break;
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		if (strlen(line) == 0)
			continue;

		cmd = strtok(line, " ");
		if (cmd == NULL)
			continue;

		execute_command(cmd);
	}

	free(line);
	return (0);
}

void execute_command(char *cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(cmd, &cmd, NULL) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
}
