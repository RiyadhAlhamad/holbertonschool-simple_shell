#include "shell.h"

/**
 * execute_command - Executes a command with arguments
 * @args: Array of command arguments
 * @program_name: Name of the shell program
 */
void execute_command(char **args, char *program_name)
{
	char *full_path = NULL;
	pid_t pid;

	if (strchr(args[0], '/') != NULL) {
		full_path = args[0];
	} else {
		full_path = find_in_path(args[0]);
	}

	if (!full_path) {
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
		return;
	}

	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
		execve(full_path, args, environ);
		perror("execve");
		_exit(EXIT_FAILURE);
	} else {
		wait(NULL);
	}

	if (full_path != args[0])
		free(full_path);
}
