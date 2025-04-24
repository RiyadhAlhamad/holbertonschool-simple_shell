#include "shell.h"

/**
 * execute_command - Executes a command with arguments
 * @args: Array of command arguments
 * @program_name: Name of the shell program
 * Return: Exit status code
 */
int execute_command(char **args, char *program_name)
{
	char *full_path = NULL;
	pid_t pid;
	int status = 0, exit_status = 0;

	if (strchr(args[0], '/') != NULL)
	{
		full_path = args[0];
	}
	else
	{
		full_path = find_in_path(args[0]);
	}

	if (!full_path)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
		return (127);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(full_path, args, environ);
		perror("execve");
		_exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
	}

	if (full_path != args[0])
		free(full_path);

	return (exit_status);
}
