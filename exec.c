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
	pid_t pid, wpid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	else
	{
		wpid = waitpid(pid, &stat, WUNTRACED);
		if (wpid == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}
