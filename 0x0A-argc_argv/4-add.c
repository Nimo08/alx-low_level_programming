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

	i = 1;

	while (i < argc)
	{

		if (nums(argv[i]))
		{
			j = atoi(argv[i]);
			res += j;
		}
		else
		{
			printf("Error\n");
			return (1);
		}
		i++;
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
