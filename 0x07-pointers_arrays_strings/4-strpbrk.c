#include "main.h"
#include <string.h>
#include <stddef.h>
/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to be scanned
 * @accept: string containing chars to match
 * Return: pointer to byte in s that matches one of the bytes in accept
 * , or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i = 0;
	unsigned int j = 1;

	while (*s != '\0' && *accept != '\0')
	{
		if (s[i] == accept[j])
		{
			return (s);
		}
		s++;
		accept++;
	}
	return (NULL);

}
