#include "main.h"
/**
 * more_numbers - prints 10 times the numbers, from 0-14
 */
void more_numbers(void)
{
	int i;
	int j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= 14; j++)
		{
			if (j != 48 && j != 57)
			{
				_putchar((j / 10 + '0'));
				_putchar((j % 10 + '0'));
			}
		}
		_putchar('\n');
	}

}