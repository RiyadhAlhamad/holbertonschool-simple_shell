#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * Function declarations for the simple shell
 */

void execute_command(char *cmd, char *program_name);

#endif /* SHELL_H */
