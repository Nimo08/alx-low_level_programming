#include "main.h"
/**
 * print_alphabet_x10 - entry point
 * Description: print alphabet 10 times in lowercase
 * Return: Always 0
 */
void print_alphabet_x10(void)
{
	int x = 0;
	int y;

	while (x < 10)
	{
		x++;

		for (y = 'a'; y <= 'z'; y++)
		{
			_putchar(y);
		}
		_putchar('\n');
	}
}
