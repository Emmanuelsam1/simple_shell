#include "shell.h"

/**
 * tokenize - tok the command
 * @arr: each command afetr being tokenized
 * @buf: the command inputed
 * @del: delimiter
 */
void tokenize(char *arr[], char *buf)
{
	char *del = "\t\n";
	char *tok;
	int i = 0;

	tok = strtok(buf, del);

	while (tok)
	{
		arr[i] = tok;
		tok = strtok(NULL, del);
		i++;
	}
	arr[i] = NULL;
}
