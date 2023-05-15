#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
/**
 * alloc_grid - returns a pointer to 2-D array of ints
 * @width: int
 * @height: int
 * Return: pointer to 2D array
 */
int **alloc_grid(int width, int height)
{
	int i;
	int **array;

	array = malloc(width * sizeof(int *));
	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}
	for (i = 0; i < width; i++)
	{
		array[i] = malloc(height * sizeof(int));
		if (array[i] == NULL)
		{
			return (NULL);
		}
	}
	return (array);

}
