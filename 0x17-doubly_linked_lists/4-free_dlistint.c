#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * free_dlistint - frees doubly linked list
 * @head: pointer
 * Return: nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *ptr;
	dlistint_t *temp = NULL;

	ptr = head;
	while (ptr != NULL)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	head = NULL;
}
