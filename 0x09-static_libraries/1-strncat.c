#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * _strncat - concatenated two strings
 * @dest: pointer
 * @src: pointer
 * @n: int
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = strlen(dest);
	int i;

	for (i = 0; i < n && dest[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
