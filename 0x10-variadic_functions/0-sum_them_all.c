#include "variadic_functions.h"
#include <stdarg.h>
/**
 * sum_them_all - returns sum of all its parameters
 * @n: const unsigned int
 * Return: sum of parameters
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;

	unsigned int num;
	unsigned int sum;

	if (n == 0)
		return (0);
	va_start(args, n);
	sum = 0;
	for (num = 0; num < n; num++)
	{
		sum += va_arg(args, unsigned int);
	}
	va_end(args);
	return (sum);
}
