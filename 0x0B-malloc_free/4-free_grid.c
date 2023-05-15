#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
/**
 * free_grid - frees a 2-D array
 * @grid: pointer to pointer
 * @height: int
 * Return: nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
	{
		for (i = 0; i < height; i++)
		{
			free(grid);
		}
	}

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
