#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_listint - prints all elements of listint_t
 * @h: struct pointer
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	const listint_t *ptr;
	int cnt = 0;

	ptr = h;
	if (ptr == NULL)
	{
		return (0);
	}
	else
	{
		while (ptr != NULL)
		{
			printf("%d\n", ptr->n);
			cnt++;
			ptr = ptr->next;
		}
	}
	return (cnt);
}
