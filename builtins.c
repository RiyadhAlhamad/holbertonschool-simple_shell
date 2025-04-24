#include "shell.h"

/**
 * is_builtin - Checks if a command is a built-in
 * @command: The command to check
 * Return: 1 if built-in, 0 otherwise
 */
int is_builtin(char *command)
{
	return (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0);
}

/**
 * handle_builtin - Executes built-in commands
 * @args: Array of command arguments
 * @last_status: Exit status of last command
 * Return: 1 if exit command was handled, 0 otherwise
 */
int handle_builtin(char **args, int last_status)
{
	if (strcmp(args[0], "exit") == 0)
	{
		/* Free resources before exiting */
		free(args);
		exit(last_status);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_env();
	}
	return (0);
}

/**
 * print_env - Prints all environment variables
 */
void print_env(void)
{
	char **env = environ;

	if (!env)
		return;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
