#include "shell.h"
#include <unistd.h>


/**
 * main - main method
 * Return: 0
 */

int main(void)
{
	char *buf;
	char **arr = malloc(sizeof(char *) * 1024);
	char *envp[] = {NULL};

	check_betty();
	_setenv();
	_unsetenv("LANG");

	while (1)
	{
		buf = _getline();

		if (strcmp(buf, "exit\n") == 0)
		{
			break;
		}

		else if (strcmp(buf, "env\n") == 0)
		{
			print_environ();
		}
		else
		{
			tokenize(arr, buf);

			if (strcmp(arr[0], "cd") == 0)
			{
				_cd(arr);
			}
			else
				execute(arr, envp);
		}
		free(arr[0]);
		free(arr);
		free(buf);
	}
		return (0);
}
