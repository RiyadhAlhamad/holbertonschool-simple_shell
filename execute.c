#include "shell.h"

char *find_command(char *cmd)
{

char *path = getenv("PATH");
char *token = strtok(path, ":");
char full_path[1024];

while (token != NULL)
{

snprintf(full_path, sizeof(full_path), "%s/%s", token, cmd);
if (access(full_path, X_OK) == 0)
return (strdup(full_path));
token = strtok(NULL, ":");

}

return (NULL);

}

/**
 * execute_command - Forks and executes given cmd string with args
 * @cmd: Command line string (may include args separated by spaces or tabs)
 * @program_name: Shell's argv[0] for error messages
 */
void execute_command(char *cmd, char *program_name)
{  
pid_t pid;
char *argv[MAX_ARGS];
int i = 0;
char *token;
char *command_path;

cmd[strcspn(cmd, "\n")] = '\0';
token = strtok(cmd, " \t");
while (token && i < MAX_ARGS - 1)
{
argv[i++] = token;
token = strtok(NULL, " \t");
}
argv[i] = NULL;
if (argv[0] == NULL)
return;
command_path = find_command(argv[0]);
if (!command_path)
{
write(STDERR_FILENO, program_name, strlen(program_name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, argv[0], strlen(argv[0]));
write(STDERR_FILENO, ": not found\n", 13);
return;
}
pid = fork();
if (pid < 0)
{
perror("fork");
free(command_path);
return;
}
if (pid == 0)
{
execve(command_path, argv, environ);
perror("execve");
free(command_path);
exit(EXIT_FAILURE);
}
else
wait(NULL);
free(command_path);
}
