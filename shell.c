#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void tokenize(char *arr[], char *buf);
void execute(char *arr[], char *envp[]);

/**
 * main - main method
 * Return: 0
 */
int main(void)
{
	char *buf = NULL;
	size_t n = 0;
	char *envp[] = {NULL};
	char **arr = malloc(sizeof(char *) * 1024);

	while (1)
	{
		printf("#cisfun$ ");
		getline(&buf, &n, stdin);
		tokenize(arr, buf);

		execute(arr, envp);
		free(arr);
	}
	return (0);
}
