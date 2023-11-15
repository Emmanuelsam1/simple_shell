#include "shell.h"

/**
 * _setenv - sets an environment variable
 */
void _setenv(void)
{
	if (setenv("AGE", "TWO", 1) != 0)
	{
		perror("ERROR");
		exit(1);
	}
}

/**
 * _unsetenv - unsets an env var
 * @var: environment variable
 */
void _unsetenv(char *var)
{
	if (unsetenv(var) != 0)
	{
		perror("ERROR");
		exit(1);
	}
}
