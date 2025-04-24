#include "shell.h"

/**
 * execute_command - Executes external commands
 * @args: Command arguments
 * @program_name: Shell program name
 * Return: Exit status of executed command
 */
int execute_command(char **args, char *program_name)
{
	char *full_path = NULL;
	pid_t pid;
	int exit_status = 0;

	if (strchr(args[0], '/'))
		full_path = args[0];
	else
		full_path = find_in_path(args[0]);

	if (!full_path)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
		return (127);
	}

	pid = fork();
	if (pid == 0)
	{
		execve(full_path, args, environ);
		perror("execve");
		/* Free if execve fails */
		free(full_path);
		_exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		waitpid(pid, &exit_status, 0);
		if (WIFEXITED(exit_status))
			exit_status = WEXITSTATUS(exit_status);
	}

	if (full_path != args[0])
		free(full_path);

	return (exit_status);
}
