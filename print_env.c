#include "shell.h"

/**
 * print_environ - prints environ
 * Return - nothing
 */

void print_environ(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
