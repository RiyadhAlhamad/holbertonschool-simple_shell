#include "shell.h"

char **parse_input(char *line) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    int i = 0;
    char *token = strtok(line, " ");

    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL; // نهاية المصفوفة بـ NULL لـ execve

    return args;
}
