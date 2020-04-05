#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int _strlen(char *str)
{
	int len;

	for (len = 0; str[len] != 0; len++)
	{
	}
	return (len);
}

int main(void)
{
        char *buffer = NULL;
        char *args[] = {"/bin/ls", "-l", NULL};

        size_t bufersize = 200;
        size_t bytes;
        int status;
        pid_t pid;
        int len;
        char * const envp[] = {NULL};

        buffer = malloc(sizeof(char) * bufersize);
        if (buffer == NULL)
                return (0);
        
        printf("#cisfun$ ");
        while((bytes = getline(&buffer, &bufersize, stdin)) > 0)
        {
                len = _strlen(buffer);
                if(buffer[len - 1] == '\n')
                        buffer[len - 1] = 0;

                if ((pid = fork()) == -1)
                {
                        perror("Error:");
		        return (1);
                }
                if (pid == 0)
	        {
                        args[0] = strtok(buffer, " "); 
		        if (execve(args[0], args, envp) == -1)
		        {
			        perror("Error:");
			        return (1);
		        }
                }
	        else
	        {
		        waitpid(pid, &status, 0);
	        }
                printf("#cisfun$ ");
        }
        free(buffer);
        return (0);
}
