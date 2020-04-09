#include <stdio.h>
#include <unistd.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
extern char **environ;

int main(int ac, char *av[], char **env)
{
        printf("env address = %p\n", (void*)env);
        printf("environ address  = %p\n", (void*)environ);
}
