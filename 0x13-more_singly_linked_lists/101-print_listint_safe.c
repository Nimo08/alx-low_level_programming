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
	const listint_t *slow_ptr;
	const listint_t *fast_ptr;
	size_t cnt = 0;

	if (head == NULL)
	{
		return (0);
	}
	slow_ptr = fast_ptr = head;
	while (slow_ptr && fast_ptr && fast_ptr->next)
	{
		printf("[%p] %d\n", (void *)slow_ptr, slow_ptr->n);
		cnt++;
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if (slow_ptr == fast_ptr)
		{
			printf("-> [%p] %d\n", (void *)slow_ptr, slow_ptr->n);
			exit(98);
		}
	}
	while (slow_ptr != NULL)
	{
		printf("[%p] %d\n", (void *)slow_ptr, slow_ptr->n);
		cnt++;
		slow_ptr = slow_ptr->next;
	}
	return (cnt);
}
