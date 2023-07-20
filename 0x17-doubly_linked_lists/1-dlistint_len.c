#include "lists.h"
#include <stdio.h>
/**
 * dlistint_len - returns number of elements in doubly linked list
 * @h: pointer
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *ptr;
	size_t len = 0;

	ptr = h;
	if (ptr == NULL)
	{
		return (0);
	}
	while (ptr != NULL)
	{
		ptr = ptr->next;
		len++;
	}
	return (len);
}
