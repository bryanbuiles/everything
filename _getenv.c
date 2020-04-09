#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
extern char **environ;
char *_strcpy1(char *dest, char *src, int flag);

char *_getenv(const char *name)
{
        int i, size;
        char *namevalue, *token, *pathvalue;
        for(i = 0; environ[i] != 0; i++)
        {
                size = _strlen(environ[i]) + 1;
                token = malloc(sizeof(char *) * size);
                if (token == NULL)
                        return (NULL);
                token = _strcpy1(token, environ[i], 0);
                namevalue = token;
                namevalue = strtok(namevalue, "=");
                if (namevalue == NULL)
                        break;
                if((strcmp(namevalue, name) == 0))
                {
                        pathvalue = _strstr(environ[i],"=");
                        free(token);
                        return(++pathvalue);
                        break;
                }
                free(token);
        }
        pathvalue = "(null)";
        return (pathvalue);
}

int main (void)
{
        printf("%s\n", _getenv("PATH"));
        return (0);
}
