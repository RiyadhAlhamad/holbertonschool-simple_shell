#include "shell.h"

/**
 * is_builtin - Checks if command is built-in
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
 * @last_status: Last command's exit status
 * Return: 1 if exit command, 0 otherwise
 */
int handle_builtin(char **args, int last_status)
{
	if (strcmp(args[0], "exit") == 0)
		return (1);
	else if (strcmp(args[0], "env") == 0)
		print_env();
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
