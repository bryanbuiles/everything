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
int sizeofnewpointer(char *token, char *av)
{
    int i, j;

    while(token[i])
    {
        i++;
    }
    while(av[j])
    {
        j++;
    }
    return(i+j);

}
int main(int ac, char **av)
{
    int j;
    unsigned int i;
    struct stat st;
    char *fullpath;
    char *token;
    int size;
    char *newpointer;

    if (ac < 2)
    {
        printf("Usage: %s path_to_file ...\n", av[0]);
        return (1);
    }
    i = 1;
    while (av[i])
    {
        //printf("%s:\n", av[i]);
        fullpath = getenv("PATH");
        
        do
        {
                token = strtok(fullpath, ":");
                size = sizeofnewpointer(token, av[i]) + 2; /*plus 2 is the null byte and the slash (/)*/
                //printf("size = %i\n", size);
                newpointer = malloc(sizeof(char *) * size);
                if(newpointer == NULL)
                    return (0);

                for(j = 0; token[j] != 0; j++)
                {
                    newpointer[j] = token[j];
                }
                newpointer[j] = '/';
                newpointer[j + 1] = '\0';

                newpointer = strcat(newpointer, av[i]);
                //printf("newpointer = %s\n", newpointer);

                if (stat(newpointer, &st) == 0)
                {
                    printf("%s\n", newpointer);
                    //printf(" FOUND\n");
                    break;
                }
                else
                {
                    //printf(" NOT FOUND\n");
                    free(newpointer);
                }
                fullpath = NULL;
        } while (token);
        i++;
    }
    free(newpointer);
    return (0);
}
