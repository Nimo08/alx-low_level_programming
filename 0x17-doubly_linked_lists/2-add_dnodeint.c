#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * add_dnodeint - adds new node at the beginning
 * @head: pointer to pointer
 * @n: int
 * Return: address of new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *ptr;

	ptr = malloc(sizeof(dlistint_t));
	if (ptr == NULL)
	{
		return (NULL);
	}
	ptr->n = n;
	ptr->next = *head;
	ptr->prev = NULL;
	if (*head != NULL)
	{
		(*head)->prev = ptr;
	}
	*head = ptr;
	return (*head);
}
