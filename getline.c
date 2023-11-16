#include "shell.h"

/**
 * _getline - gets a line inputed from user
 * Return: the line
 */
#define n 4096

char *_getline(void)
{
	static char data[n];
	size_t length = 0;
	char *theLine;
	size_t i;
	size_t check = 0;

	theLine = malloc(sizeof(char) * length);
	if (!theLine)
		exit(1);

	check = read(STDIN_FILENO, data, n);

	if (check <= 0)
		return (NULL);


	while (length < check && data[length] != '\n')
		length++;

	if (length < check)
		length++;

	for (i = 0; i < length; i++)
		theLine[i] = data[i];
	theLine[length] = '\0';

	return (theLine);
}
