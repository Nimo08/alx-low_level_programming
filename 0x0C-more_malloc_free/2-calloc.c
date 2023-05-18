#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _memset - fills first n bytes with constant byte
 * @str: char pointer
 * @b: char
 * @n: number of bytes
 * Return: char pointer
 */
char *_memset(char *str, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
	{
		str[x] = b;
	}
	return (str);
}
/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: elements in array
 * @size: number of bytes
 * Return: pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr = 0;

	if (nmemb == 0 || size == 0)
	{
		return (0);
	}
	ptr = malloc(size * nmemb);
	if (ptr == NULL)
	{
		return (NULL);
	}
	_memset(ptr, 0, nmemb * size);
	return (ptr);
}
