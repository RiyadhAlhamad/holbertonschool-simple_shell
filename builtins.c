#include "shell.h"

int is_builtin(char *command) {
    return (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0);
}

void handle_builtin(char **args) {
    if (strcmp(args[0], "exit") == 0) {
        free(args);
        exit(EXIT_SUCCESS);
    } else if (strcmp(args[0], "env") == 0) {
        print_env();
    }
}

void print_env(void) {
    extern char **environ;
    for (char **env = environ; *env; env++) {
        printf("%s\n", *env);
    }
}
