#include "main.h"
/**
 * binary_to_uint - converts binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 * Return: converted number, or 0 if there is one or more chars in b
 * that is not 0 or 1
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int res = 0;
	unsigned int i;

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
		{
			return (0);
		}
		res *= 2;
		res += b[i] - '0';
	}
	return (res);
}
