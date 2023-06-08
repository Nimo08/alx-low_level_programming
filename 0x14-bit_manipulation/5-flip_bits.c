#include "main.h"
#include <stddef.h>
/**
 * flip_bits - return number of bits you would need to flip to get from
 * one number to another
 * @n: unsigned long integer
 * @m: unsigned long integer
 * Return: number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int val;
	unsigned int cnt = 0;

	val = n ^ m;
	if (val == 0)
	{
		return (-1);
	}
	while (val)
	{
		val = val & (val - 1);
		cnt++;
	}
	return (cnt);
}
