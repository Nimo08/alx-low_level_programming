#include <stdio.h>
/**
  * main - Entry point
  * Description: print all possible combinations
  * of single-digit numbers
  * Return: Always 0 (Success)
  */

int main(void)
{
	int x;

	for (x = 0; x < 10; x++)
	{
		putchar('0' + x);
		if (x < 9)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
