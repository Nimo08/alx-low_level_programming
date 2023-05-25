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
	const char *str;

	va_start(args, n);
	for (num = 0; num < n; num++)
	{
		str = va_arg(args, const char *);
		if (str == NULL)
		{
			printf("nil");
		}
		printf("%s", str);
		if (num < n - 1 && separator != NULL)
		{
			printf("%s", separator);
		}
	}
	va_end(args);
	printf("\n");
}
