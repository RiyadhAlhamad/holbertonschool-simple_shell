#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_ARGS 64
#define BUFFER_SIZE 1024

extern char **environ;

/* Function prototypes */
char **parse_input(char *line);
char *find_in_path(char *command);
int execute_command(char **args, char *program_name);
int is_builtin(char *command);
int handle_builtin(char **args);
void print_env(void);

#endif /* SHELL_H */
