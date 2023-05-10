#include "main.h"
/**
 * _sqrt_recursion - returns natural square root of a number
 * @n: integer
 * Return: square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (_sqrt_natural(n, 1));
}
/**
 * _sqrt_natural - compute natural square root
 * @n: int
 * @x: int
 * Return: natural square root
 */
int _sqrt_natural(int n, int x)
{
	if ((x * x) == n)
	{
		return (x);
	}
	if ((x * x) > n)
	{
		return (-1);
	}
	return (_sqrt_natural(n, x + 1));
}

