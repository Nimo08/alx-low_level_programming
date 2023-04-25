#include <stdio.h>
/**
 * main - entry point
 * Return: always 0
 */
int main(void)
{
	int i = 0;
	unsigned long int a = 0, b = 1, next = 0;

	while (i < 95)
	{
		next = a + b;
		a = b;
		b = next;

		if (i < 94)
			printf(", ");
		i++;
		printf("%lu", next);
	}
	printf("\n");
	return (0);
}
