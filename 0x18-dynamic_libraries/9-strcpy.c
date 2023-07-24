#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * _strcpy - copies the string
 * @dest: pointer
 * @src: pointer
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int j;

	while (*(src + i) != '\0')
	{
		i++;
	}
	for (j = 0; j < i; j++)
	{
		dest[j] = src[j];
	}
	dest[i] = '\0';
	return (dest);
}
