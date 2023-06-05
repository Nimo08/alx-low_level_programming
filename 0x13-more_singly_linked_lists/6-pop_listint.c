#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * pop_listint - deletes the head node of listint_t
 * @head: pointer to pointer to struct
 * Return: head node's data (n)
 */
int pop_listint(listint_t **head)
{
	listint_t *ptr;
	int data;

	if (*head == NULL)
	{
		return (0);
	}
	ptr = *head;
	*head = ptr->next;
	data = ptr->n;
	free(ptr);
	if (ptr == NULL)
	{
		return (-1);
	}
	return (data);
}
