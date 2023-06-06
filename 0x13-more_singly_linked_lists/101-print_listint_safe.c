#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_listint_safe - prints listint_t
 * @head: struct pointer
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *ptr;
	size_t cnt = 0;

	if (head == NULL)
	{
		return (0);
	}
	ptr = head;
	while (ptr != NULL)
	{
		printf("[%p] %d\n", (void *)ptr, ptr->n);
		cnt++;
		if (ptr <= ptr->next && ptr->next != NULL)
		{
			printf("-> [%p] %d\n", (void *)ptr, ptr->n);
			exit(98);
		}
		ptr = ptr->next;
	}
	return (cnt);
}
