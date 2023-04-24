#include <stdio.h>

/**
 * main - Entry point
 * Description: print all possible different combinations
 * of three digits
 * Return: Always 0 (Success)
 */

int main(void)
{
	int x;
	int y;
	int z;

	for (x = 0; x <= 7; x++)
	{
		for (y = x + 1; y <= 8; y++)
		{
			for (z = y + 1; z <= 9; z++)
			{
				putchar('0' + x);
				putchar('0' + y);
				putchar('0' + z);
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
