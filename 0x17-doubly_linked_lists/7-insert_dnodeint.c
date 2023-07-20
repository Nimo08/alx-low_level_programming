#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer
 * @idx: index of the list where the node should be added
 * @n: int
 * Return: address of new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *ptr;
	dlistint_t *temp;

	if (h == NULL)
	{
		return (NULL);
	}
	ptr = *h;
	temp = malloc(sizeof(dlistint_t));
	if (temp == NULL)
	{
		return (NULL);
	}
	temp->n = n;
	temp->prev = NULL;
	temp->next = NULL;
	if (idx == 0)
	{
		temp->next = *h;
		if (*h != NULL)
			(*h)->prev = temp;
		(*h) = temp;
		return (temp);
	}
	while (idx != 0 && ptr != NULL)
	{
		ptr = ptr->next;
		idx--;
	}
	if (ptr == NULL)
	{
		free(temp);
		return (NULL);
	}
	temp->next = ptr;
	temp->prev = ptr->prev;
	if (ptr->prev != NULL)
		ptr->prev->next = temp;
	ptr->prev = temp;
	return (temp);
}
