#include "main.h"
#include <string.h>
/**
 * infinite_add - adds two numbers stored as strings
 * @n1: first number string
 * @n2: second number string
 * @r: buffer to store result
 * @size_r: size of buffer
 *
 * Return: pointer to result string, or 0 if result cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, len = 0, carry = 0, sum = 0, i = 0, j = 0;

	len1 = strlen(n1);
	len2 = strlen(n2);
	len = len1 > len2 ? len1 : len2;

	if (len >= size_r)
		return (0);
	for (i = 0; i < len; i++)
	{
		int d1 = i < len1 ? n1[len1 - 1 - i] - '0' : 0;
		int d2 = i < len2 ? n2[len2 - 1 - i] - '0' : 0;

		sum = d1 + d2 + carry;
		carry = sum / 10;
		r[len - 1 - i] = sum % 10 + '0';
	}
	if (carry)
	{
		if (len + 1 >= size_r)
			return (0);
		r[len] = carry + '0';
		r[len + 1] = '\0';
	}
	else
	{
		r[len] = '\0';
	}
	for (j = 0; j < len / 2; j++)
	{
		char tmp = r[j];

		r[j] = r[len - 1 - j];
		r[len - 1 - j] = tmp;
	}
	return (r);
}
