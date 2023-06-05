#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * delete_nodeint_at_index - deletes node at index of listint_t
 * @head: pointer to pointer to struct
 * @index: index of the node that should be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *ptr;
	listint_t *temp;
	listint_t *prev;
	unsigned int cnt = 0;

	ptr = *head;
	if (ptr == NULL)
	{
		return (-1);
	}
	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	if (index > 0)
	{
		temp = prev = *head;
		while (cnt < index)
		{
			prev = temp;
			temp = temp->next;
			cnt++;
		}
		prev->next = temp->next;
		free(temp);
	}
	return (1);
}
