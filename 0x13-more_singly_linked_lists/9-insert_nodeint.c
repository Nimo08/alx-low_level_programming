#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to pointer to struct
 * @idx: index of the list where the new node should be added
 * @n: integer
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *ptr;
	listint_t *temp;

	ptr = *head;
	temp = malloc(sizeof(listint_t));
	if (temp == NULL)
	{
		return (NULL);
	}
	temp->n = n;
	if (idx == 0)
	{
		temp->next = *head;
		*head = temp;
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
