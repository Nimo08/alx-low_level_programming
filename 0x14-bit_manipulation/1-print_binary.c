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

	while (bit_mask > 0)
	{
		if ((n & bit_mask) == 0)
			putchar('0');
		else
			putchar('1');
		bit_mask = bit_mask >> 1;
	}
}
