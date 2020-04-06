#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - stat example
 *
 * Return: Always 0.
 */
int _strlen(char *token)
{
	int i = 0;

	while(token[i])
	{
		i++;
	}
	return(i);
}
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while(dest[i])
	{
		i++;
	}
	while((dest[i] = src[j]) != 0)
	{
		i++;
		j++;
	}
	return (dest);
}
char *_strcpy1(char *dest, char *src, int flag)
{
	int i;
	
	for (i = 0; src[i] != 0; i++)
	{
		dest[i] = src[i];
	}
	if (flag == 1)
	{
		dest[i] = '/';
		i++;
	}
	dest[i] = '\0';
        return(dest);

}
int main(int ac, char **av)
{
	int size = 0;
	unsigned int i = 0;
	struct stat st;
	char *fullpath, *token = NULL, *newpointer = NULL, *fullpathtemp;

	if (ac < 2)
	{
		printf("...\n");
		return (1);
	}

	fullpath = getenv("PATH");
	/*creating a new copy fo fullpath so strtok doesn't modified  call fullpathtemp*/
	size = _strlen(fullpath) + 1;
	fullpathtemp = malloc(sizeof(char *) * size);
	if (fullpathtemp == NULL)
		return (0);

	i = 1;
	while (av[i])
	{
		
		fullpathtemp = _strcpy1(fullpathtemp, fullpath, 0);
		token = strtok(fullpathtemp, ":");
		
		do
		{
			token = strtok(NULL, ":");
			if (token == NULL)
				break;
			size = 0;
			size = _strlen(token) + _strlen(av[i]) + 2; /*plus 2 is the null byte and the slash (/)*/
			newpointer = malloc(sizeof(char *) * size);
			if(newpointer == NULL)
				return (0);
                        newpointer = _strcpy1(newpointer, token, 1);
			newpointer = _strcat(newpointer, av[i]);
			if (stat(newpointer, &st) == 0)
			{
				printf("%s\n", newpointer);
				break;
			}
			else
			{
				free(newpointer);
				newpointer = NULL;
			}
		} while (token);
		i++;
	}
	free(newpointer);
	free(fullpathtemp);
	return (0);
}
