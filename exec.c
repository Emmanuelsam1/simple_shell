#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/**
 * execute - executes the command
 * @arr: the command
 * @envp: NULL
 */
void execute(char *arr[], char *envp[])
{
	int stat;
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("error: fork");
		exit(1);
	}

	if (pid == 0)
	{
		if (execve(arr[0], arr, envp) == -1)
		{
			perror("./shell");
		}
	}
	else
		wait(&stat);
}
