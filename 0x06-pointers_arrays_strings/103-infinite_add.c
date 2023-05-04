#include "main.h"
#include <string.h>
/**
 * reverse - Reverses a string
 * @r: String to reverse
 * Return: void
 */
char *reverse(char *r)
{
	int i, j;
	char tmp;

	for (i = 0, j = strlen(r) - 1; i < j; i++, j--)
	{
		tmp = r[i];
		r[i] = r[j];
		r[j] = tmp;
	}
	return (r);
}
/**
 * infinite_add - Adds two numbers
 * @n1: First number to add
 * @n2: Second number to add
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 * Return: Pointer to the result if success, 0 if result can't be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int ium, jum, kum, lum, mum, nun, sum;

	ium = strlen(n1) - 1;
	jum  = strlen(n2) - 1;
	kum = 0;
	lum = 0;
	while (ium >= 0 || jum >= 0)
	{
		mum = (ium >= 0) ? (n1[ium] - '0') : 0;
		nun = (jum >= 0) ? (n2[jum] - '0') : 0;
		sum = mum + nun + kum;

		if (lum >= size_r - 1)
		{
			return (0);
		}
		r[lum++] = (sum % 10) + '0';
		kum = sum / 10;
		ium--;
		jum--;
	}
	if (kum > 0)
	{
		if (lum >= size_r - 1)
		{
			return (0);
		}
		r[lum++] = kum + '0';
	}
	r[lum] = '\0';
	reverse(r);
	if (strlen(r) >= (size_t)size_r)
	{
		return (0);
	}
	return (r);
}
