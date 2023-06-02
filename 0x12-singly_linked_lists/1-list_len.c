#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
/**
 * list_len - returns number of elements in linked list list_t
 * @h: pointer to struct
 * Return: number of elements in list_t
 */
size_t list_len(const list_t *h)
{
	const list_t *ptr;
	size_t len = 0;

	ptr = h;
	while (ptr != NULL)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}
