#include "shell.h"

/**
 * _srttok - strtok function
 * @s: the character
 * @del: the delimeter
 * Return: pointer to the token
 */
char *_strtok(char *s, const char *del)
{
	char *first;
	static char *tok_pntr = NULL;

	if (s != NULL)
		tok_pntr = s;
	else if (tok_pntr == NULL)
		return (NULL);

	first = tok_pntr;
	while (*tok_pntr != '\0' && (strchr(del, *tok_pntr) != NULL))
		tok_pntr++;

	if (*tok_pntr == '\0')
	{
		tok_pntr = NULL;
		return (NULL);
	}

	while (*tok_pntr != '\0' && (strchr(del, *tok_pntr) == NULL))
		tok_pntr++;

	if (*tok_pntr != '\0')
	{
		*tok_pntr = '\0';
		tok_pntr++;
	}

	return (first);

}
