#include "shell.h"

/**
 * parse_line - Tokenize a command line into arguments
 * @line: The input line
 *
 * Return: Array of tokens (arguments)
 */
char **parse_line(char *line)
{
	char *token;
	char **args;
	int i = 0;
	const int MAX_ARGS = 64;

	args = malloc(sizeof(char *) * MAX_ARGS);
	if (!args)
	{
		perror("malloc");
		return (NULL);
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
