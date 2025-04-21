#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 64

/**
 * execute_command - Forks and executes given cmd string with args
 * @cmd: Command line string (newline removed)
 * @program_name: Shell's argv[0] for error prefix
 */
void execute_command(char *cmd, char *program_name);

extern char **environ;

#endif /* SHELL_H */
