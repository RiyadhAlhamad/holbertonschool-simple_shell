#include "shell.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		write(1, "($) ", 4);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			write(1, "\n", 1);
			exit(0);
		}
		line[read - 1] = '\0'; // remove newline
		execute_command(line);
	}
	free(line);
	return (0);
}
