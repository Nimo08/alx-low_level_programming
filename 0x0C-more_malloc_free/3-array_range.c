#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * array_range - creates an array of ints
 * @min: lowest value
 * @max: highest value
 * Return: pointer to newly created array
 */
int *array_range(int min, int max)
{
	int i;
	int *ptr;

	if (min > max)
	{
		return (NULL);
	}
	ptr = malloc(sizeof(ptr) * (max - min) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= max; i++)
	{
		ptr[i] = ptr[max - min] + i;
	}
	return (ptr);
}
