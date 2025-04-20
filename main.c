#include "shell.h"

/**
 * main - The entry point of the shell program
 * Return: Always 0
 */

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1)
    {
        /* Display prompt */
        write(STDOUT_FILENO, "$ ", 2);

        /* Read user input */
        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            free(line);
            break;
        }

        /* Remove newline character */
        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        /* Check if the input is an empty string */
        if (strlen(line) == 0)
            continue;

        /* Tokenize input (if there are multiple commands) */
        char *cmd = strtok(line, " ");
        if (cmd == NULL)
            continue;

        /* Execute the command */
        execute_command(cmd);
    }

    /* Free the memory allocated for line */
    free(line);
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
 * _strdup - Duplicates a string (basic version)
 * @str: The string to duplicate
 * Return: A pointer to the newly allocated string
 */

char *_strdup(const char *str)
{
    char *dup = malloc(strlen(str) + 1);
    if (!dup)
    {
        perror("malloc");
        exit(1);
    }
    strcpy(dup, str);
    return (dup);
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
