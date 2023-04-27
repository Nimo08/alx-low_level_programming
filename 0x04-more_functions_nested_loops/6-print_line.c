#include "main.h"
/**
 * print_line - draws straight line in the terminal
 * @n: number of times the character _ should be printed
 */
void print_line(int n)
{
	int i;
	int j;

	for (i = 1; i <= n; i++)
	{
		for (j = i; j >= 1; j--)
		{
			if (n > 0)
			{
				j = j % 2;
				_putchar('_');
			}
			else
			{
				_putchar('\n');
			}
		}
	}
	_putchar('\n');
}
