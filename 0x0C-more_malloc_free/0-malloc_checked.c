#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * malloc_checked - allocates memory using malloc
 * @b: unsigned int
 * Return: pointer to allocated memory
 */
void *malloc_checked(unsigned int b)
{
	unsigned int i;

	int *ptr = malloc(sizeof(ptr) * b);

	if (ptr == NULL)
	{
		exit(98);
	}
	for (i = 0; i < b; i++)
	{
		ptr[i] = 0;
	}
	return (ptr);
}
