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
	const listint_t *ptr = NULL;
	const listint_t *temp;
	size_t cnt = 0;
	size_t cnt1;

	temp = head;
	while (temp)
	{
		printf("[%p] %d\n", (void *)temp, temp->n);
		cnt++;
		temp = temp->next;
		ptr = head;
		cnt1 = 0;
		while (cnt1 < cnt)
		{
			if (temp == ptr)
			{
				printf("-> [%p] %d\n", (void *)temp->next, temp->n);
				return (cnt);
			}
			ptr = ptr->next;
			cnt1++;
		}
		if (head == NULL)
		{
			exit(98);
		}
	}

	return (cnt);
}
