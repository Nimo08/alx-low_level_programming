#include "main.h"
#include <stdio.h>
/**
 * print_binary - prints binary representation of a number
 * @n: unsigned long int
 * Return: nothing
 */
void print_binary(unsigned long int n)
{
	unsigned long int bit_mask = 32768;
	int zeros = 1;

	if (n == 0)
	{
		putchar('0');
	}
	while (bit_mask > 0)
	{
		if ((n & bit_mask) != 0)
		{
			zeros = 0;
			putchar('1');
		}
		else if (!zeros)
		{
			putchar('0');
		}
		bit_mask = bit_mask >> 1;
	}
}
