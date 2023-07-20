#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * get_dnodeint_at_index - returns nth node of doubly linked list
 * @head: pointer to first node
 * @index: position of the node
 * Return: nth node of list
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *ptr;
	unsigned int len = 0;

	ptr = head;
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (ptr != NULL)
	{
		if (len == index)
		{
			return (ptr);
		}
		len++;
		ptr = ptr->next;
	}
	return (NULL);
}
