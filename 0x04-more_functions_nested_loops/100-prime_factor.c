#include "main.h"
#include <stdio.h>

/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	long num = 612852475143;
	int max_factor = 0;
	int odd_num = 3;

	while (num % 2 == 0)
	{
		max_factor = 2;
		num /= 2;
	}
	while (num != 1)
	{
		while (num % odd_num == 0)
		{
			max_factor = odd_num;
			num /= odd_num;
		}
		odd_num += 2;
	}
	printf("%d\n", max_factor);
	return (0);

}
