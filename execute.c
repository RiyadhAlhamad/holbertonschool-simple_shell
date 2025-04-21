#include "shell.h"

/**
 * execute_command - Forks and executes the given command string
 * @cmd: The full command string input by user
 * @program_name: Name of the executable program (used in error message)
 */

void execute_command(char *cmd, char *program_name)
{
	pid_t pid;
	char *argv[2];

	cmd[strcspn(cmd, "\n")] = '\0';

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		return;
	}
	if (pid == 0)
	{
		argv[0] = cmd;
		argv[1] = NULL;
		if (execve(cmd, argv, environ) == -1)
		{
			write(STDERR_FILENO, program_name, strlen(program_name));
			write(STDERR_FILENO, ": 1: ", 5);
			write(STDERR_FILENO, cmd, strlen(cmd));
			write(STDERR_FILENO, ": not found\n", 13);
			exit(127);
		}
	}
	else
	{
		wait(NULL);
	}
}
