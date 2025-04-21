#include "shell.h"

void execute_command(char *cmd)
{
	pid_t pid;
	char *argv[2];

	argv[0] = cmd;
	argv[1] = NULL;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd, argv, environ) == -1)
		{
			perror("./hsh");
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
