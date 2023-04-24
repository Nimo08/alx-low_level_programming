#include <stdio.h>

/**
 * main - Entry point
 * Description: print numbers of base 16 in lowercase
 * Return: Always 0 (Success)
 */

int main(void)
{
	int x;
	int y;

	for (x = 0; x <= 9; x++)
	{
		putchar('0' + x);
	}

	for (y = 'a'; y <= 'f'; y++)
	{
		putchar(y);
	}
	putchar('\n');
	return (0);
}
