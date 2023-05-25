#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_strings - print strings
 * @separator: const char pointer
 * @n: const unsigned int
 * Return: nothing
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int num;
	char *str;

	num = 0;

	if (n == 0)
		return;
	if (separator == NULL)
		return;
	va_start(args, n);
	while (num < n)
	{
		str = va_arg(args, char *);
		if (str == NULL)
		{
			printf("nil");
		}
		else
		{
			printf("%s", str);
		}
		if (num < n - 1)
		{
			printf("%s", separator);
		}
		num++;
	}
	printf("\n");
	va_end(args);
}
