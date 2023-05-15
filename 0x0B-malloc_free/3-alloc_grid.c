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

	array = (int **) malloc(width * sizeof(int *));
	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}
	for (i = 0; i < width; i++)
	{
		array[i] = (int *) malloc(height * sizeof(int));
		for (j = 0; j < height; j++)
		{

			if (array[i] == NULL)
			{
				return (NULL);
			}
			array[i][j] = 0;
		}
	}
	return (array);

	if (array == NULL)
	{
		for (i = 0; i < width; i++)
		{
			free(array[i]);
		}
		free(array);
	}

}
