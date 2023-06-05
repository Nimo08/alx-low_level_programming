#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * sum_listint - returns sum of all data(n) of listint_t
 * @head: struct pointer
 * Return: sum of all data(n)
 */
int sum_listint(listint_t *head)
{
	listint_t *ptr;
	int data_sum = 0;

	ptr = head;
	if (ptr == NULL)
	{
		return (0);
	}
	while (ptr != NULL)
	{
		data_sum += ptr->n;
		ptr = ptr->next;
	}
	return (data_sum);
}
