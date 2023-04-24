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

	for (x = 48; x < 58; x++)
	{
		for (y = 48; y < 58; y++)
		{
			if (y > x)
			{
				for (z = 48; z < 58; z++)
				{
					if (z > y)
					{
						putchar(x);
						putchar(y);
						putchar(z);
						if (x == 55 && y == 56 && z == 57)
						{
							break;
						}
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
