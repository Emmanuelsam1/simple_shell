#include <stdio.h>

/**
 * main - main method
 * Return: 0
 */
int main(void)
{
	int i;

	printf("Single digit numbers are: ");

	for (i = 0; i < 10; i++)
	{
		if (i == 9)
			printf("%d\n", i);
		else
			printf("%d, ", i);
	}
	return (0);
}
