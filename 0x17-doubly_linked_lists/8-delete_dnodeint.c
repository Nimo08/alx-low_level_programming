#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * delete_dnodeint_at_index - deletes node at an index
 * @head: pointer to pointer
 * @index: index of node that should be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *ptr;
	dlistint_t *temp;

	if (*head == NULL)
	{
		return (-1);
	}
	ptr = *head;
	if (index == 0)
	{
		*head = ptr->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(ptr);
		return (1);
	}
	while (index > 0  && ptr != NULL)
	{
		ptr = ptr->next;
		index--;
	}
	if (ptr == NULL)
	{
		return (-1);
	}
	temp = ptr->prev;
	temp->next = ptr->next;
	if (ptr->next != NULL)
		ptr->next->prev = temp;
	free(ptr);
	return (1);
}
