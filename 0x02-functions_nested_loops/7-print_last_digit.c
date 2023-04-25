#include "main.h"
/**
 * print_last_digit - entry point
 * @x: number to be checked
 * Description: print last digit of number
 * Return: value of last digit
 */
int print_last_digit(int x)
{
	int y;

	y = x % 10;
	if (x < 0)
	{
		y = y * -1;
	}
	_putchar(y + '0');
	return (y);
}
