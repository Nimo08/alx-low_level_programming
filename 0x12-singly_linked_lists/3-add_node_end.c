#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * add_node_end - adds a new node at the end of list_t
 * @head: pointer to pointer to struct
 * @str: constant char pointer
 * Return: address of new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *ptr;
	list_t *temp;

	ptr = *head;
	temp = malloc(sizeof(list_t));
	if (temp == NULL)
	{
		return (NULL);
	}
	temp->str = strdup(str);
	temp->len = strlen(str);
	temp->next = NULL;
	if (*head == NULL)
	{
		*head = temp;
		return (temp);
	}
	else
	{
		ptr = *head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
	}
	ptr->next = temp;
	return (temp);
}
