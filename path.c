#include "shell.h"

/**
 * find_in_path - Searches for command in PATH environment variable
 * @command: Command to search for
 * 
 * Return: Full path if found, NULL otherwise
 */
char *find_in_path(char *command)
{
    char *path, *path_copy, *dir, *full_path;
    int cmd_len, dir_len;

    path = getenv("PATH");
    if (!path)
        return (NULL);

    path_copy = strdup(path);
    if (!path_copy)
        return (NULL);

    cmd_len = strlen(command);
    dir = strtok(path_copy, ":");
    full_path = NULL;

    while (dir)
    {
        dir_len = strlen(dir);
        full_path = malloc(dir_len + cmd_len + 2);
        if (!full_path)
            break;

        snprintf(full_path, dir_len + cmd_len + 2, "%s/%s", dir, command);
        if (access(full_path, X_OK) == 0)
            break;

        free(full_path);
        full_path = NULL;
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return (full_path);
}
