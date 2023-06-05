#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * listint_len - returns number of elements in listint_t
 * @h: struct pointer
 * Return: number of elements
 */
size_t listint_len(const listint_t *h)
{
	const listint_t *ptr;
	size_t len = 0;

	ptr = h;
	while (ptr != NULL)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}
