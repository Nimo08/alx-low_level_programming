#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * sum_dlistint - returns sum of all the data(n)
 * @head: pointer to first node
 * Return: sum of data
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *ptr;

	if (head == NULL)
	{
		return (0);
	}
	ptr = head;
	while (ptr != NULL)
	{
		sum += ptr->n;
		ptr = ptr->next;
	}
	return (sum);
}
