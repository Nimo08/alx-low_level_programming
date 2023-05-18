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
	{
		len++;
	}
	return (len);
}
/**
 * product - multiplies two positive numbers
 * @num1: first int
 * @num2: second int
 * Return: result
 */
int product(int num1, int num2)
{
	return (num1 * num2);
}
/**
 * is_num - checks for number
 * @str: char pointer
 * Return: 0 or 1
 */
int is_num(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/**
 * _atoi - converts a string to int
 * @str: char pointer
 * Return: int
 */
int _atoi(char *str)
{
	int res = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		res = res * 10 + (str[i] - '0');
	}
	return (sign * res);
}
/**
 * print_num  - prints an int
 * @num: int
 * Return: nothing
 */
void print_num(int num)
{
	if (num / 10)
	{
		print_num(num / 10);
	}
	_putchar (num % 10 + '0');
}
/**
 * main - check arguments
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int num1;
	int num2;
	int res;
	(void)  argv;

	if (argc != 3)
	{
		write(1, "Error\n", 6);
		exit(98);
	}
	if (!is_num(argv[1]) || !is_num(argv[2]))
	{
		write(1, "Error\n", 6);
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	res = product(num1, num2);
	if (res < 0)
	{
		_putchar('-');
		res = -res;
	}
	print_num(res);
	_putchar('\n');
	return (0);
}
