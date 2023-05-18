#include "main.h"
#include <stdlib.h>
#include <ctype.h>
/**
 * product - multiplies two positive numbers
 * @mul: result
 * @num1: first int
 * @num2: second int
 * Return: result
 */
int product(int num1, int num2)
{
	int mul;
	mul = num1 * num2;
	_putchar('\n');
	return (mul);
}
/**
 * main - check arguments
 * @argc - argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *str;
	str = "Error";
	if (argc < 2)
	{
		_putchar('\n');
		return (str);
		exit(98);
	}
	if (isdigit(num1) != 0)
	{
		_putchar('\n');
		return (str);
		exit(98);
	}
	if (isdigit(num2) != 0)
	{
		_putchar('\n');
		return (str);
		exit(98);
	}
	return (0);
}
