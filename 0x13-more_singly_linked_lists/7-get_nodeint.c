#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * get_nodeint_at_index - returns the nth node of listint_t
 * @head: struct to pointer
 * @index: index of the node, starting at 0
 * Return: nth node, if it doesn't exist, return NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *ptr;
	unsigned int cnt = 0;

	ptr = head;
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (ptr != NULL)
	{
		if (cnt == index)
		{
			return (ptr);
		}
		cnt++;
		ptr = ptr->next;
	}
	return (ptr);
}
