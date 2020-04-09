#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "holberton.h"
/**
 * _setenv - set a new variable or replace if it exist when  overwrite is 1, 
 * @name: name of the variable VAR
 * @value: value of the variable VAR=var-value
 * @overwrite: if VAR exist and overwrite != 0, value will be replace
 * Return: -1 if name has and (=) equal sign, 0 on success
 */
extern char **environ;

int _setenv(char *name, char *value, int overwrite)
{
        int i, size = 0, newSize = 0, index = 0;
        char *envName = NULL, **newEnv = NULL;
        int matchName = 0, flag = 0;
        

        /*evalua si name has an = sign return (-1), otherwise if there isn't will be NULL keep the running the program*/
        if((strchr(name, '=') != NULL))
                return (-1);
        
        /* count the size of environ, if there is a match flag will be 1 */ 
        for (size = 0; environ[size]; size++) 
        {
                envName = strdup(environ[size]);
                envName = strtok(envName, "="); /*Divide la string con el primer = */
                if((strcmp(name, envName)) == 0)
                        matchName = 1;
                free(envName);
        }
        size++;


        // Calculate allocation size
        if (matchName == 1) /* Match is 1, so size is the same */
                newSize = size;
        else
                newSize = size + 1; /* for adding the new Var */

        // Allocate memory
        newEnv = malloc(sizeof(char *) * newSize);
        if (newEnv == NULL)
                return (0);

        // Copy enviorn to newEnv and reassign if necessary
        for (i = 0; environ[i]; i++) 
        {
                envName = strdup(environ[i]);
                envName = strtok(envName, "="); /*Divide la string con el primer = */
                if(strcmp(name, envName) == 0 && overwrite != 0)
                        newEnv = envValue(name, value, newEnv, i), index = i, flag = 1;
                else
                        newEnv[i] = environ[i];
                free(envName);
        }
        /* if there isn't match add the new VAR=var-value */
        if (matchName == 0)
                newEnv = envValue(name, value, newEnv, (i - 1)), index = i - 1, flag = 1;
        /* newSize is == (i-1) */
        newEnv[i] = '\0';


       /* para testear como quedo la lista y liberar memoria */
        for (i = 0; newEnv[i]; i++)
                printf("%s\n", newEnv[i]);
        if (flag)
                free(newEnv[index]);
        free(newEnv);       
        //environ = newEnv;
        return (0);

}
int main(void)
{
        //  printf("%i\n", _setenv("PATH=", "ERIKA", 1));
        //  _setenv("PATH", "ERIKA", 0);
        //  _setenv("NAME", "erikaosgue", 0);
        //  _setenv("NAME", "-->ERIKAOSORIO", 0);
        //  _setenv("NAME", "ERIKAOSORIO", 1);
        _setenv("BIRTHDAY", "04131994", 1);
       return (0);
}
