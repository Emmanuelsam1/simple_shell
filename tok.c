#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * tokenize - tok the command
 * @arr: each command afetr being tokenized
 * @buf: the command inputed
 */
void tokenize(char *arr[], char *buf)
{
	char *del = " \t\n";
	char *tok;
	char *tok2;
	char *del2 = ":";
	char join_pth[1024];
	int i = 0;
	int x = 0;

	char *tok1;
	char *del1 = "/\t\n";
	char **a = malloc(sizeof(char *) * 1024);
	int z = 0;

	char *pth = getenv("PATH");
	char *pth_cp = strdup(pth);

	tok = strtok(buf, del);

	while (tok)
	{
		arr[i] = tok;
		tok = strtok(NULL, del);
		i++;
	}
	arr[i] = NULL;

	tok1 = strtok(arr[0], del1);

	while (tok1)
	{
		a[z] = tok1;
		tok1 = strtok(NULL, del1);
		z++;
	}
	z--;

	tok2 = strtok(pth_cp, del2);

	while (tok2)
	{
		sprintf(join_pth, "%s/%s", tok2, a[z]);

		if (access(join_pth, F_OK) == 0)
		{
			x = 1;
			break;
		}

		tok2 = strtok(NULL, del2);
	}

	if (x == 1)
		arr[0] = strdup(join_pth);
	else
	{
		perror("./shell not found");
		exit(1);
	}
}
