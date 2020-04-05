#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(int c, char *v[], char **env)
{
	char *exePath = "/bin/ls";
	pid_t pid[5];
	pid_t child;
	int i, status;

	for (i = 0; i < 5; i++)
	{
		if ((pid[i] = fork()) == -1)
		{
			perror("Error:");
			return (1);
		}
		if (pid[i] == 0)
		{
			child = getpid();
			dprintf(STDOUT_FILENO, "child # %u\n", child);
			if (execve(exePath, v, env) == -1)
			{
				perror("Error:");
				return (1);
			}
		}
		else
		{
			waitpid(pid[i], &status, 0);
			printf("Hijo # %d\n", i);
		}
	}
	return (0);
}
