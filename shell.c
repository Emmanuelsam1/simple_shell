#include "shell.h"
#include <unistd.h>

extern char **environ;

/**
 * main - main method
 * Return: 0
 */

int main(void)
{
	char *buf = NULL;
	size_t n = 0;
	char **arr;

	while (1)
	{
		printf("#cisfun$ ");
		getline(&buf, &n, stdin);

		if(strcmp(buf, "exit\n") == 0)
		{
			break;
		}

		else if (strcmp(buf, "env\n") == 0)
		{
            		print_environ(environ);
		}
		else
		{
			tokenize(arr, buf);

			execute(arr, environ);
			free(arr);
		}
	}

		free(buf);

		return (0);
}
