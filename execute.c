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
	while (token != NULL)
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
 * @cmd: Command line string (may include arguments separated by spaces or tabs)
 * @program_name: Shell program name (argv[0]) for error messages
 */
void execute_command(char *cmd, char *program_name)
{
	pid_t pid;
	char *argv[MAX_ARGS];
	int i = 0;
	char *token;
	char *command_path = NULL_*
