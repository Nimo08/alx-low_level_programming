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
	size_t cnt = 0;

	ptr = h;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		cnt++;
		ptr = ptr->next;
	}
	return (cnt);
}
