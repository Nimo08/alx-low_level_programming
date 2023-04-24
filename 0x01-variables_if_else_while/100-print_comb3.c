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

	while (x < 90)
	{
		putchar('0' + (x / 10));
		putchar('0' + (x % 10));
		x++;
		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);
}
