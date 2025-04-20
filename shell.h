#ifndef SHELL_H
#define SHELL_H

/*
 * File: shell.h
 * Description: Header file for the simple shell project.
 * Contains function prototypes and included libraries.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_INPUT_SIZE 1024

/* Function Prototypes */
char *custom_getline(void);
void execute_command(char *cmd);
char *read_input(void);
void _strdup(char *str);
size_t _strlen(const char *s);

#endif /* SHELL_H */
