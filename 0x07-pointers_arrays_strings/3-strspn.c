#include "main.h"
#include <string.h>
/**
 * _strspn - gets length of a prefix substring
 * @s: string to be scanned
 * @accept: string containing chars to match
 * Return: number of bytes in initial segment of s
 * which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int n = 0;
	unsigned int len1 = strlen(s);
	unsigned int len2 = strlen(accept);
	unsigned int i, j;

	for (i = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
		{
			if (accept[j] == s[i])
				break;
		}
		if (accept[j] != s[i])
			break;
		n++;
	}
	return (n);
}
