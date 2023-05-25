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

	if (n == 0)
		return;
	va_start(args, n);
	for (num = 0; num < n; num++)
	{
		res = va_arg(args, int);
		printf("%d", res);
		if (separator == NULL)
			return;
		if (num < n - 1)
			printf("%s", separator);
	}
	printf("\n");
	va_end(args);
}
