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
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
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
		i++;
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
	int rev;
	int count;
	int temp;

	if (num == 0)
	{
		_putchar('0');
		return;
	}
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	rev = 0;
	count = 0;
	temp = num;
	while (temp > 0)
	{
		rev = rev * 10 + (temp % 10);
		temp /= 10;
		count++;
	}
	while (count > 0)
	{
		_putchar(rev % 10 + '0');
		rev /= 10;
		count--;
	}
}
/**
 * main - check arguments
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int res;

	if (argc != 3 || !is_num(argv[1]) || !is_num(argv[2]))
	{
		write(1, "Error\n", _strlen("Error\n"));
		exit(98);
	}
	res = product(_atoi(argv[1]), _atoi(argv[2]));
	if (res < 0)
	{
		_putchar('-');
		res = -res;
	}
	print_num(res);
	_putchar('\n');
	return (0);
}
