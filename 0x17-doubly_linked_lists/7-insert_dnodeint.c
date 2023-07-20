#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * dlistint_len1 - returns number of elements in doubly linked list
 * @h: pointer
 * Return: number of elements
 */
unsigned int dlistint_len1(const dlistint_t *h)
{
	const dlistint_t *ptr;
	unsigned int len = 0;

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

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer
 * @idx: index of the list where the node should be added
 * @n: int
 * Return: address of new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *ptr, *temp;

	if (idx > dlistint_len1(*h))
		return (NULL);
	ptr = *h;
	temp = malloc(sizeof(dlistint_t));
	if (temp == NULL)
	{
		free(temp);
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
	while (idx != 0 && ptr->next != NULL)
	{
		ptr = ptr->next;
		idx--;
	}
	if (ptr->next == NULL && idx != 0)
	{
		ptr->next = temp;
		temp->prev = ptr;
		return (temp);
	}
	temp->next = ptr;
	temp->prev = ptr->prev;
	if (ptr->prev != NULL)
		ptr->prev->next = temp;
	if (ptr != NULL)
		ptr->prev = temp;
	return (temp);
}
