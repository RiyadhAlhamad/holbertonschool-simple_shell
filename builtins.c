#include "shell.h"

/**
 * is_builtin - Checks if command is a built-in
 * @command: Command to check
 * Return: 1 if built-in, 0 otherwise
 */
int is_builtin(char *command)
{
	return (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0);
}

/**
 * handle_builtin - Handles built-in commands
 * @args: Command arguments
 * @status: Pointer to store exit status
 * Return: 1 for exit command, 0 otherwise
 */
int handle_builtin(char **args, int *status)
{
	if (strcmp(args[0], "exit") == 0)
	{
		return (1);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_env();
		*status = 0;
	}
	return (0);
}

/**
 * print_env - Prints environment variables
 */
void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
