#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * free_listint2 - frees listint_t
 * @head: pointer to pointer to struct
 * Return: nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *ptr;
	listint_t *temp;

	ptr = *head;
	while (ptr != NULL)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	*head = NULL;
}
