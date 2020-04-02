#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main()

{
    char *buffer;
    size_t bufsize = 200;
    size_t redline;
    int wr, wy;

    buffer = malloc(sizeof(char) * bufsize);
    if (buffer == NULL)
        return (0);
    dprintf(STDOUT_FILENO, "$ ");
    redline = getline(&buffer, &bufsize, stdin);
    wr = write(STDOUT_FILENO, buffer, redline);
    if (wr == -1)
        exit(98);
    free(buffer);
    return (wr);
}
