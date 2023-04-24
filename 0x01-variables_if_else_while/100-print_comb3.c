#include <stdio.h>

/**
 * main - Entry point
 * Description: prints all possible combinations of
 * 2 digits
 * Return: Always 0 (Success)
 */
int main(void)
{
	int x;
	int y;

	for (x = 48; x <= 56; x++) 
	{
		for (y = 49; y <= 57; y++)
		{
			if (y > x)
			{
				putchar(x);
				putchar(y);
				if ( x != 56 || y != 57)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
