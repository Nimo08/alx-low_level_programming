#include "main.h"
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
/**
 * _strlen - length of a string
 * @s: char pointer
 * Return: string length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}
/**
 * is_num - checks for number
 * @str: char pointer
 * Return: 0 or 1
 */
int is_num(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/**
 * main - check arguments
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *str1, *str2;
	int len1, len2, len, i, j, num1, num2, *res, a;

	a = 0;
	str1 = argv[1];
	str2 = argv[2];
	if (argc != 3 || !is_num(str1) || !is_num(str2))
	{
		write(1, "Error\n", _strlen("Error\n"));
		exit(98);
	}
	len1 = _strlen(str1);
	len2 = _strlen(str2);
	len = len1 + len2 + 1;
	res = malloc(sizeof(int) * len);
	if (!res)
		return (1);
	for (i = 0; i <= len1 + len2; i++)
		res[i] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		num1 = str1[len1] - '0';
		j = 0;
		for (len2 = _strlen(str2) - 1; len2 >= 0; len2--)
		{
			num2 = str2[len2] - '0';
			j += res[len1 + len2 + 1] + (num1 * num2);
			res[len1 + len2 + 1] = j % 10;
			j /= 10;
		}
		if (j > 0)
			res[len1 + len2 + 1] += j;
	}
	for (i = 0; i < len - 1; i++)
	{
		if (res[i])
			a = 1;
		if (a)
			_putchar(res[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(res);
	return (0);
}
