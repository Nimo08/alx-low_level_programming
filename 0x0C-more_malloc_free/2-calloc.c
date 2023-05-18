#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: elements in array
 * @size: number of bytes
 * Return: pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *ptr = 0;

	if (nmemb == 0 || size == 0)
	{
		return (0);
	}
	ptr = malloc(sizeof(ptr) * size * nmemb);
	if (ptr == NULL)
	{
		return (0);
	}
	for (i = 0; i < size; i++)
	{
		ptr[i] = ptr[nmemb];
	}
	return (ptr);
}
