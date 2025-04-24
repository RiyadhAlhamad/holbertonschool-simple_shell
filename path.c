#include "shell.h"

/**
 * find_in_path - Searches for command in PATH environment variable
 * @command: Command to search for
 * Return: Full path if found, NULL otherwise
 */
char *find_in_path(char *command)
{
    char *path = NULL;
    char *path_copy = NULL;
    char *dir = NULL;
    char *full_path = NULL;
    int found = 0;

    /* Manual search for PATH in environ */
    for (char **env = environ; *env != NULL; env++)
    {
        if (strncmp(*env, "PATH=", 5) == 0)
        {
            path = *env + 5;
            break;
        }
    }

    if (!path)
        return (NULL);

    path_copy = strdup(path);
    if (!path_copy)
        return (NULL);

    dir = strtok(path_copy, ":");
    while (dir != NULL)
    {
        int dir_len = strlen(dir);
        int cmd_len = strlen(command);

        full_path = malloc(dir_len + cmd_len + 2);
        if (!full_path)
        {
            free(path_copy);
            return (NULL);
        }

        snprintf(full_path, dir_len + cmd_len + 2, "%s/%s", dir, command);

        if (access(full_path, X_OK) == 0)
        {
            found = 1;
            break;
        }

        free(full_path);
        full_path = NULL;
        dir = strtok(NULL, ":");
    }

    free(path_copy);

    return (found ? full_path : NULL);
}
