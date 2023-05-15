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
	int j;
	int **array;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}
	array = (int **) malloc(width * sizeof(int *));
	if (array == NULL)
	{
		free(array);
		return (NULL);
	}
	for (i = 0; i < width; i++)
	{
		array[i] = (int *) malloc(height * sizeof(int));
		if (array[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(array[j]);
			}
			free(array);
			return (NULL);
		}
		for (j = 0; j < height; j++)
		{
			array[i][j] = 0;
		}
	}
	return (array);

}
