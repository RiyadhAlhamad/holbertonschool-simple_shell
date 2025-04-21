#include "shell.h"

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

	/* إزالة الـ newline في نهاية السطر */
	cmd[strcspn(cmd, "\n")] = '\0';

	/* تقسيم السطر حسب الفراغات أو التب */
	token = strtok(cmd, " \t");
	while (token && i < MAX_ARGS - 1)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL;

	/* إذا السطر كان فارغ أو مسافات فقط، نتجاهله */
	if (argv[0] == NULL)
		return;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			write(STDERR_FILENO, program_name, strlen(program_name));
			write(STDERR_FILENO, ": 1: ", 5);
			write(STDERR_FILENO, argv[0], strlen(argv[0]));
			write(STDERR_FILENO, ": not found\n", 13);
			exit(127);
		}
	}
	else
		wait(NULL);
}
