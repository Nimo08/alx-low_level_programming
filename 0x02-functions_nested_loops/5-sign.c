#include "main.h"
/**
 * print_sign - entry point
 * @n: number to be checked
 * Description: prints sign of a number
 * Return: 1 if +, 0 if 0, -1 if less than zero
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
