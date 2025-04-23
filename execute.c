#include "shell.h"

/**
 * find_command - Searches for a command in the directories listed in PATH
 * @cmd: Command name to search for
 *
 * Return: Full path to the command if found, NULL otherwise
 */
char *find_command(char *cmd)
{
	char *path = NULL;
	char *token;
	char full_path[1024];
	int i = 0;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = strdup(environ[i] + 5);
			break;
		}
		i++;
	}

	if (!path)
		return (NULL);

	token = strtok(path, ":");
	while (token)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", token, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (strdup(full_path));
		}
		token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}

/**
 * execute_command - Forks and executes a given command string with arguments
 * @cmd: Command line string (may include args separated by spaces or tabs)
 * @program_name: Shell program name (argv[0]) for error messages
 *
 * Return: Exit status of executed command
 */
int execute_command(char *cmd, char *program_name)
{
	pid_t pid;
	char *argv[MAX_ARGS];
	int i = 0, wstatus;
	char *token;
	char *command_path = NULL;
	int exit_status = 0;

	/* strip newline */
	cmd[strcspn(cmd, "\n")] = '\0';

	/* split into argv */
	token = strtok(cmd, " \t");
	while (token && i < MAX_ARGS - 1)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL;

	if (!argv[0])
		return (0);

	/* direct path? */
	if (access(argv[0], X_OK) == 0)
		command_path = strdup(argv[0]);
	else
		command_path = find_command(argv[0]);

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		free(command_path);
		return (127);
	}
	else if (pid == 0)
	{
		/* Child */
		if (!command_path)
		{
			write(STDERR_FILENO, program_name, strlen(program_name));
			write(STDERR_FILENO, ": 1: ", 5);
			write(STDERR_FILENO, argv[0], strlen(argv[0]));
			write(STDERR_FILENO, ": not found\n", 12);
			exit(127);
		}
		execve(command_path, argv, environ);
		perror("execve");
		free(command_path);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent waits */
		wait(&wstatus);
		if (WIFEXITED(wstatus))
			exit_status = WEXITSTATUS(wstatus);
	}

	free(command_path);
	return (exit_status);
}
