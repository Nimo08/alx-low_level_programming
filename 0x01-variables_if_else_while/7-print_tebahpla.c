#include <stdio.h>
#include<string.h>

/**
 * main - Entry point
 * Description: prints lowercase alphabet in
 * reverse order
 * Return: Always 0 (Success)
 */
int main(void)
{
	int x;

	for (x = 'a'; x <= 'z'; x--)
	{
		putchar(x);
	}
	putchar('\n');
	return (0);
}
