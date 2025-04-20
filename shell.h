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
extern char **environ;
int _shell(void);
char *_strdup(const char *str);

#endif /* SHELL_H */
