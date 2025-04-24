#include "shell.h"

/**
 * parse_input - Splits input string into command arguments
 * @line: Input string to parse
 * 
 * Return: NULL-terminated array of arguments
 */
char **parse_input(char *line)
{
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *token;
    int i = 0;

    if (!args)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " ");
    while (token != NULL && i < MAX_ARGS - 1)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    return (args);
}
