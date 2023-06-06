#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * free_listint_safe - frees listint_t
 * @h: pointer to pointer to struct
 * Return: size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *ptr;
	listint_t *temp;
	size_t cnt = 0;
	int cnt1;

	if (h == NULL || *h == NULL)
	{
		return (0);
	}
	ptr = *h;
	cnt = 0;
	while (ptr != NULL)
	{
		cnt1 = ptr - ptr->next;
		if (cnt1 > 0)
		{
			temp = ptr->next;
			free(ptr);
			ptr = temp;
			cnt++;
		}
		else
		{
			free(ptr);
			cnt++;
			break;
		}
	}
	*h = NULL;
	return (cnt);
}
