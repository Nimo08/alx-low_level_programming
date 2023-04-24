#include <stdio.h>

/**
 * main - Entry point
 * Description: prints lowercase alphabet in reverse
 * Return: Always 0 (Success)
 */

int main(void)
{
	int x;

	for (x = 'z'; x >= 'a'; x--)
	{
		putchar(x);
	}
	putchar('\n');
	return (0);
}
