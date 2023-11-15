#include "shell.h"
#include <unistd.h>
#include <sys/wait.h>
/**
 * execute - executes the command
 * @args: the command
 * @envp: NULL
 */
void execute(char **args, char **envp)
{
	int stat;
	pid_t pid;

	stat = 0;
	pid = fork();

	if (pid == -1)
	{
		perror("ERROR");
		exit(1);
	}

	if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
	else
		wait(&stat);
}
