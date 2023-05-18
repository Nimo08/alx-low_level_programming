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
	int range;

	range = max - min + 1;

	if (min > max)
	{
		return (NULL);
	}
	ptr = malloc(sizeof(int) * range);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; min <= max; i++)
	{
		ptr[i] = min++;
	}
	return (ptr);
}
