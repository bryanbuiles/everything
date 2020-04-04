#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(int c, char *v[], char *env[])
{
    pid_t pid;
    int status;
    char *buffer = NULL;
    size_t bufsize = 0;
    size_t redline;
    int j = 0;
    char *exePath;

    typedef struct opf
    {
        char *por;
        char *f;
    } commands_t;

    commands_t asc[] = {
        {"./pid", "/home/usr/everything/pic"},
        {"./ppid", "/home/usr/everything/ppic"},
        {"bin/ls", "bin/ls"},
        {NULL, NULL}};

    //char env[] = {"user=/home/bryan/everything/", "PATH=/bin:/usr/bin", 0};

    dprintf(STDOUT_FILENO, "$ ");
    while ((redline = getline(&buffer, &bufsize, stdin)) > 0)
    {
        if ((pid = fork()) == -1)
        {
            perror("Error:");
            return (1);
        }
        if (pid == 0)
        {
            char *token = strtok(buffer, " ");
            printf("v[0] %s\n", token);
            for (j = 0; asc[j].por != NULL || token == (asc[j].por); j++)
            {
                printf("hola\n");
            }
            if (asc[j].por)
                exePath = (asc[j].f);
            printf("%s\n", exePath);
            //chdir("/home/bryan/everything/pid");
            int ret = execve(exePath, v, env);
            if (ret == -1)
            {
                perror("Error:");
                return (1);
            }
        }
        else
        {
            waitpid(pid, &status, 0);
        }
        dprintf(STDOUT_FILENO, "$ ");
    }
    free(buffer);
    return (0);
}
