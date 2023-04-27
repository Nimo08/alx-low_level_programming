#include "main.h"
/**
 * print_line - draws straight line in the terminal
 * @n: number of times the character _ should be printed
 */
void print_line(int n)
{
	int c;

	for (c = 0; n <= 4; c++)
	{
		for (n = 0; n <= 10; n++)
		{
			_putchar('_');
		}
	}
	_putchar('\n');
}
