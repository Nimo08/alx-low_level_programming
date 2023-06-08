#include "main.h"
#include <stdio.h>
/**
 * get_bit - returns value of bit at a given index
 * @n: unsigned long int
 * @index: index, starting from 0 of the bit you want to get
 * Return: value of bit at index, or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int bit_val;

	if (n == 0)
	{
		return (-1);
	}
	if (n != 0)
	{
		bit_val = (n >> index & 1);
	}
	return (bit_val);

}
