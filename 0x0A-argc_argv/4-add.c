#include "main.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i;
	int j;
	int res = 0;

	if (argc == 0)
	{
		printf("0\n");
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		char *arg = argv[i];

		if (*arg == '-' || *arg == '+')
		{
			arg++;
		}

		if (!isdigit(*arg))
		{
			printf("Error\n");
			return (1);
		}
		j = atoi(argv[i]);

		if (j <= 0)
		{
			printf("Error\n");
			return (1);
		}
		res += j;
	}
	printf("%d\n", res);
	return (0);
}
