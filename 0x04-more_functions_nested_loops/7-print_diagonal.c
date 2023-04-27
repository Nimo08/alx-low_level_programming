#include "main.h"

/**
 * print_diagonal - draws diagonal line om terminal
 * @n: number of times \ is printed
 */
void print_diagonal(int n)
{
	int i;
	int j;

	if (n <= 0)
	{
		_putchar('\n');
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (j == i)
			{
				_putchar('\\');
			}
			else
			{
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
	_putchar('\n');
}
