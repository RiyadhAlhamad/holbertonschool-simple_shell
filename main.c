#include "shell.h"

/**
 * main - The entry point of the shell program
 * Return: Always 0
 */

int main(void)
{
char *input = NULL;
char *cmd = NULL;
size_t len = 0;
ssize_t nread;

while (1)
{
/* Display prompt */
printf("$ ");

/* Read user input */
nread = getline(&input, &len, stdin);
if (nread == -1)
{
perror("getline");
free(input);
exit(1);
}

/* Remove newline character */
input[nread - 1] = '\0';

/* Check if the input is an empty string */
if (strlen(input) == 0)
continue;

/* Tokenize input (if there are multiple commands) */
cmd = strtok(input, " ");
if (cmd == NULL)
continue;

/* Execute the command */
execute_command(cmd);
}
free(input);
return (0);
}

/**
 * execute_command - Executes the command entered by the user
 * @cmd: The command to be executed
 */

void execute_command(char *cmd)
{
pid_t pid;
int status;

pid = fork();
if (pid == -1)
{
perror("fork");
exit(1);
}
else if (pid == 0)
{
/* Execute the command */
if (execve(cmd, &cmd, NULL) == -1)
{
perror("execve");
exit(1);
}
}
else
{
/* Parent process: wait for child process to finish */
wait(&status);
}
}

/**
 * read_input - Reads input from the user
 * Return: The input string
 */

char *read_input(void)
{
char *input = NULL;
size_t len = 0;
ssize_t nread;

nread = getline(&input, &len, stdin);
if (nread == -1)
{
perror("getline");
exit(1);
}

/* Remove newline character */
input[nread - 1] = '\0';
return (input);
}

/**
 * _strdup - Duplicates a string (basic version)
 * @str: The string to duplicate
 * Return: A pointer to the newly allocated string
 */

void _strdup(char *str)
{
char *dup = malloc(strlen(str) + 1);
if (!dup)
{
perror("malloc");
exit(1);
}
strcpy(dup, str);
}

/**
 * _strlen - Returns the length of a string
 * @s: The string to measure
 * Return: The length of the string
 */

size_t _strlen(const char *s)
{
size_t length = 0;

while (*s++)
length++;

return (length);
}
