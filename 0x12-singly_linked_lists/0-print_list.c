#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	const list_t *ptr;
	size_t cnt = 0;

	ptr = h;
	while (ptr != NULL)
	{
		if (ptr->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%u] ", ptr->len);
			printf("%s\n", ptr->str);
		}
		cnt++;
		ptr = ptr->next;
	}
	return (cnt);
}
