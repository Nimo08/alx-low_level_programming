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
	int res = 0;

	if (argc == 1)
	{
		printf("%d\n", res);
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		if (!isdigit(argv[i][0]) && argv[i][0] != '-' && argv[i][0] != '+')
		{
			printf("Error\n");
			return (1);
		}
		res += atoi(argv[i]);
	}
	printf("%d\n", res);
	return (0);
}
