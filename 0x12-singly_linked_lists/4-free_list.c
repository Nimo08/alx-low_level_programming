#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * free_list - frees list_t
 * @head: struct pointer
 * Return: nothing
 */
void free_list(list_t *head)
{
	list_t *ptr;
	list_t *temp;

	ptr = head;
	while (ptr != NULL)
	{
		temp = ptr->next;
		free(ptr->str);
		free(ptr);
		ptr = temp;
	}
	head = NULL;
}
