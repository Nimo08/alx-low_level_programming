#include "lists.h"
#include <stdio.h>
/**
 * print_dlistint - prints all elements of list
 * @h: pointer
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *ptr;
	size_t cnt = 0;

	ptr = h;
	if (ptr == NULL)
	{
		return (0);
	}
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
		cnt++;
	}
	return (cnt);
}
