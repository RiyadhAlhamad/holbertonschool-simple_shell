#include "shell.h"

/**
 * main - Entry point of the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Exit status
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;
	int status = 0;

	(void)argc;

	while (1) {
		if (isatty(STDIN_FILENO))
			printf("$ ");

		read = getline(&line, &len, stdin);
		if (read == -1) {
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		line[strcspn(line, "\n")] = '\0';
		if (strlen(line) == 0)
			continue;

		args = parse_input(line);
		if (args[0] != NULL) {
			if (is_builtin(args[0])) {
				handle_builtin(args);
			} else {
				status = execute_command(args, argv[0]);
			}
		}
		free(args);
	}

	free(line);
	return (status);
}
