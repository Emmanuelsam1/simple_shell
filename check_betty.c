#include "shell.h"

/**
 * check_betty - passes betty
 * Return: nain
 */

void check_betty(void)
{
	int i;
	char *a;

	a = malloc(sizeof(char) * 10);
	if (a == NULL)
		exit(1);
	for (i = 0; i < 10; i++)
	{
		a[i] = 5;
	}
}
