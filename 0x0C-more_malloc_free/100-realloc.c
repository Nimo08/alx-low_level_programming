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
	void *new_ptr;
	unsigned char *ptr1;
	unsigned char *ptr2;

	if (ptr == NULL)
	{
		return (malloc(new_size));
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size < old_size)
	{
		return (ptr);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}
	ptr1 = (unsigned char *)ptr;
	ptr2 = (unsigned char *)new_ptr;

	for (i = 0; i < old_size && i < new_size; i++)
	{
		ptr2[i] = ptr1[i];
	}
	free(ptr);
	return (new_ptr);
}
