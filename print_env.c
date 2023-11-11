#include <stdio.h>
#include <stdlib.h>

extern char **environ;

void print_environ(void)
{
	int i = 0;

	while (environ[i] != NULL)
    	{
		printf("%s\n", environ[i]);
		i++;
	}
}
