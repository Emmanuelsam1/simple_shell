#include "shell.h"

/**
 * main - main method
 * Return: 0
 */
int main(void)
{
	char *buf = NULL;
	size_t n = 0;
	char *envp[] = {NULL};
	char **arr;

	while (1)
	{
		printf("#cisfun$ ");
		getline(&buf, &n, stdin);

		if(strcmp(buf, "exit\n") == 0)
		{
			break;
		}



		tokenize(arr, buf);

		execute(arr, envp);
		free(arr);

	}
	free(buf);

	return (0);
}
