#include "shell.h"

void execute_command(char **args)
{
    char *full_path = NULL;

    if (strchr(args[0], '/') != NULL)
    {
        full_path = args[0];
    } else {
        full_path = find_in_path(args[0]);
    }

    if (!full_path)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return;
    }

    pid_t pid = fork();
    if (pid == 0)
    {
        execve(full_path, args, environ);
        perror("execve");
        _exit(EXIT_FAILURE);
    } else if (pid > 0)
    {
        wait(NULL);
    } else
    {
        perror("fork");
    }
}
