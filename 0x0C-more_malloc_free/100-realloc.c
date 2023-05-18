#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: previously allocated memory block
 * @old_size: size of previously allocated space
 * @new_size: size of new memory block
 * Return: newly allocated space
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	int *new_ptr;
	unsigned int min_size;

	min_size = (new_size < old_size) ? new_size : old_size;

	if (new_size < old_size)
	{
		return (ptr);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	if (ptr == NULL)
	{
		new_ptr = malloc(sizeof(int));
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(sizeof(new_ptr) * new_size);
	for (i = 0; i < min_size; i++)
	{
		new_ptr[i] = i;
	}
	return (new_ptr);
}
