#include "main.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
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

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
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
/**
 * nums - checks for digit
 * @s: char pointer
 * Return: 1
 */
int nums(char *s)
{
	unsigned int i;

	i = 0;
	while (i < strlen(s))
	{
		if (!isdigit(s[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
