#include "main.h"
#include "math.h"
/**
 * is_prime_number - returns 1 if int is prime, 0 if not
 * @n: int
 * Return: 1 if prime or 0 if not
 */
int is_prime_number(int n)
{
	return (is_prime(n, 2));
}
/**
 * is_prime - checks for prime numbers
 * @n: int
 * @x: int
 * Return: 1 if prime, 0 otherwise
 */
int is_prime(int n, int x)
{
	if (n < 2)
	{
		return (0);
	}
	if (x > _sqrt(n, x))
	{
		return (1);
	}
	if (n % x == 0)
	{
		return (0);
	}
	return (is_prime(n, x + 1));

}
/**
 * _sqrt - returns square root
 * @n: int
 * @i: int
 * Return: square root of n
 */
int _sqrt(int n, int i)
{
	if ((i * i) == n)
	{
		return (i);
	}
	if ((i * i) > n)
	{
		return (-1);
	}
	return (_sqrt(n, i + 1));
}
