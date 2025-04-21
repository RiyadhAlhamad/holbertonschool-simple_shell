#include "shell.h"
extern char **environ;

/**
 * execute_command - Forks and execve's the given cmd
 * @cmd: Command line string with args separated by spaces
 * @program_name: argv[0] of shell, used for error prefix
 */
void execute_command(char *cmd, char *program_name)
{
	pid_t pid;
	char *argv[64];
	int i = 0;
	char *token;

	cmd[strcspn(cmd, "\n")] = '\0';
	token = strtok(cmd, " ");
	while (token != NULL && i < 63)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			write(STDERR_FILENO, program_name, strlen(program_name));
			write(STDERR_FILENO, ": 1: ", 5);
			write(STDERR_FILENO, argv[0], strlen(argv[0]));
			write(STDERR_FILENO, ": not found\n", 13);
			exit(127);
		}
	}
	else
	{
		wait(NULL);
	}
}
