#include "shell.h"

/**
 * parse_input - Splits input line into arguments
 * @line: Input line to parse
 * Return: NULL-terminated array of arguments
 */
char **parse_input(char *line)
{
	char **args = malloc(MAX_ARGS * sizeof(char *));
	char *token;
	int i = 0;

	if (!args)
	{
		/* Free input line on malloc failure */
		free(line);
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " ");
	while (token && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	return (args);
}
