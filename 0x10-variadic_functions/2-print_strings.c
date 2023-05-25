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

	va_start(args, n);
	num = 0;
	while (num < n)
	{
		str = va_arg(args, char *);
		printf("%s", str == NULL ? "nil" : str);
		if (num < n - 1 && separator != NULL)
		{
			printf("%s", separator);
		}
		num++;
	}
	va_end(args);
	printf("\n");
}
