#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++)
    {
        char *token = strtok(argv[i], ":");
        while (token != NULL)
        {
            dprintf(STDOUT_FILENO, "%s\n", token);
            token = strtok(NULL, ":");
        }
    }
    return (0);
}
