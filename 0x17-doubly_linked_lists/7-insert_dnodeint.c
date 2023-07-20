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

	ptr = *h;
	temp = malloc(sizeof(dlistint_t));
	if (temp == NULL)
	{
		return (NULL);
	}
	temp->n = n;
	if (idx == 0)
	{
		temp->next = *h;
		(*h) = temp;
		return (temp);
	}
	while (idx != 1 && ptr != NULL)
	{
		ptr = ptr->next;
		idx--;
	}
	if (ptr == NULL)
	{
		free(temp);
		return (NULL);
	}
	temp->next = ptr->next;
	ptr->next = temp;
	return (temp);
}
