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
	//char *myArray[] = {NULL, NULL, NULL, NULL};
	pid_t pid[5];
	pid_t child;
	int i, status;
	//myArray[0] = v[0];
	//myArray[1] = v[1];
	//myArray[2] = v[2];

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
			execve(exePath, v, env);
			printf("hola\n");
			sleep(10);
			exit(100 + i);
		}
		else
		{
			waitpid(pid[i], &status, 0);
			printf("Exit status %d\n", WEXITSTATUS(status));
		}
	}
	return (0);
}
