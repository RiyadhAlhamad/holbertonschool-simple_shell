#include "shell.h"

char *find_in_path(char *command) {
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    char *full_path = malloc(BUFFER_SIZE);

    while (dir != NULL) {
        snprintf(full_path, BUFFER_SIZE, "%s/%s", dir, command);
        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return full_path;
        }
        dir = strtok(NULL, ":");
    }

    free(full_path);
    free(path_copy);
    return NULL;
}
