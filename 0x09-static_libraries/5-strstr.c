#include "main.h"
#include <string.h>
#include <stddef.h>
/**
 * _strstr - finds first occurrence of substring needle in
 * string haystack
 * @haystack: main string
 * @needle: substring
 * Return: pointer to starts of located substring
 * or NULL if substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *temp1 = haystack;
		char *temp2 = needle;

		while (*haystack && *temp2 && *haystack == *temp2)
		{
			haystack++;
			temp2++;
		}
		if (!(*temp2))
		{
			return (temp1);
		}
		haystack = temp1 + 1;
	}
	return (NULL);
}
