#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * reverse_listint - reverses listint_t
 * @head: pointer to pointer to struct
 * Return: pointer to first node of reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *ptr;
	listint_t *temp;

	ptr = *head;
	while (ptr->next != NULL)
	{
		temp = ptr->next;
		ptr->next = temp->next;
		temp->next = *head;
		*head = temp;
	}
	return (*head);
}
