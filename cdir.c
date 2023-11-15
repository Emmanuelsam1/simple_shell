#include "shell.h"

/**
 * _cd - changes directory
 * @arr: the cd command
 */
void _cd(char *arr[])
{
	char *dir;
	char *curDir;
	const int cur_size = 1024;

	curDir = malloc(sizeof(char) * cur_size);
	if (curDir == NULL)
	{
		perror("malloc fail");
		exit(1);
	}

	if (!(arr[1]))
		dir = getenv("HOME");
	else if (strcmp(arr[1], "-") == 0)
	{
		dir = getenv("OLDPWD");
		if (!dir)
		{
			perror("No previous directiry");
			exit(1);
		}
	}
	else
		dir = strdup(arr[1]);

	if (getcwd(curDir, cur_size) == NULL)
	{
		perror("get directory fail");
		exit(1);
	}
	setenv2("OLDPWD", curDir, 1);

	if (chdir(dir) != 0)
	{
		perror("change dir fail");
		exit(1);
	}
	setenv2("PWD", dir, 1);
	free(dir);
	free(curDir);
}

/**
 * setenv2 - set env
 * @var: the env var
 * @l: the new dir
 * @n: 1 for overwrite
 */
void setenv2(char *var, char *l, int n)
{
	if (setenv(var, l, n) == -1)
	{
		perror("setenv fail");
		exit(1);
	}
}
