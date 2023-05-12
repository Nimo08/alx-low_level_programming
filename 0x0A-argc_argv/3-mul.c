#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 1 if less than 2 args, 0 otherwise
 */
int main(int argc, char *argv[])
{
	int i;
	int res = 1;

	if (argc < 3)
	{
		printf("Error\n");
		return (1);
	}
	for (i = 1; i < argc; i++)
	{
		res *= atoi(argv[i]);
	}
	printf("%d\n", res);
	return (0);

}
