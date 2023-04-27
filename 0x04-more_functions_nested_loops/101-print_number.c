#include "main.h"
/**
 * print_number - prints int
 * @n: int
 * Return: 0
 */
void print_number(int n)
{
	int x = 1;
	int m;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	m = n;
	while (m >= 10)
	{
		m = m / 10;
		x *= 10;
	}

	while (x > 0)
	{
		int digit = n / x;

		_putchar(digit + '0');
		n -= digit * x;
		x /= 10;
	}
}
