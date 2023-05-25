#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_numbers - prints numbers
 * @separator: const char pointer
 * @n: const unsigned int
 * Return: nothing
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int num;
	int res;

	va_start(args, n);
	num = 0;
	if (n == 0)
		return;
	while (num < n)
	{
		res = va_arg(args, int);
		printf("%d", res);
		if (separator == NULL)
			return;
		if (num < n - 1)
			printf("%s", separator);
		num++;
	}
	va_end(args);
	printf("\n");
}
