#include "shell.h"

/**
 * main - Entry point of simple shell
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Last command's exit status
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args = NULL;
	int status = 0;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		line[strcspn(line, "\n")] = '\0';
		args = parse_input(line);

		if (args[0])
		{
			if (is_builtin(args[0]))
			{
				if (handle_builtin(args, status))
				{
					free(args);
					free(line);
					exit(status);
				}
				free(args);
			}
			else
			{
				status = execute_command(args, argv[0]);
				free(args);
			}
		}
		else
		{
			free(args);
		}
		args = NULL;
	}

	free(line);
	return (status);
}
