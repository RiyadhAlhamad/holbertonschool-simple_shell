#include <shell.h>

/**
 * main - prints the parent process ID (PPID)
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t ppid;

	ppid = getppid();
	printf("%u\n", ppid);
	return (0);
}
