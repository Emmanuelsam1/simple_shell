#include "shell.h"

/**
 * tokenize - tok the command
 * @arr: each command afetr being tokenized
 * @buf: the command inputed
 */
void tokenize(char *arr[], char *buf)
{
	char *del = " \t\n";
	char *tok;

	int i = 0;

	char *tok1;
	char *del1 = "/\t\n";
	char **a = malloc(sizeof(char *) * 1024);
	int z = 0;



	tok = _strtok(buf, del);

	while (tok)
	{
		arr[i] = tok;
		tok = _strtok(NULL, del);
		i++;
	}
	arr[i] = NULL;

	tok1 = _strtok(arr[0], del1);

	while (tok1)
	{
		a[z] = tok1;
		tok1 = _strtok(NULL, del1);
		z++;
	}
	z--;

	if (strcmp(arr[0], "cd") != 0)
		token_path(arr, a[z]);

}

/**
 * token_path - tokenize path
 * @arr: command
 * @y: the element to join with pth to compare
 */

void token_path(char *arr[], char *y)
{
	char *tok2;
	char *del2 = ":";
	char join_pth[1024];
	char *pth = getenv("PATH");
	char *pth_cp = strdup(pth);
	int x;


	tok2 = _strtok(pth_cp, del2);

	while (tok2)
	{
		sprintf(join_pth, "%s/%s", tok2, y);

		if (access(join_pth, F_OK) == 0)
		{
			x = 1;
			break;
		}

		tok2 = _strtok(NULL, del2);
	}

	if (x == 1)
		arr[0] = strdup(join_pth);
	else
	{
		perror("./shell not found");
		free(pth_cp);
		exit(1);

	}
	free(pth_cp);
}
