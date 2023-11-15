#include "search_algos.h"
#include <stdio.h>
#include <math.h>
/**
 * jump_list - searches for a value in a sorted list of integers
 * using the Jump search algorithm
 * @list: pointer to the head of the list to search in
 * @size: number of nodes in list
 * @value: value to search for
 * Return: pointer to the first node where value is located
 * If value is not present in head or if head is NULL,
 * your function must return NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *curr, *temp;
	size_t start = 0, end = sqrt(size);

	if (list == NULL)
	{
		return (NULL);
	}
	curr = temp = list;
	/*loop to jump*/
	while (temp->index + 1 < size && temp->n < value)
	{
		curr = temp;
		for (start += end; temp->index < start; temp = temp->next)
		{
			if (temp->index + 1 == size)
			{
				break;
			}
		}
		printf("Value checked at index [%ld] = [%d]\n", temp->index,
				temp->n);
	}
	printf("Value found between indexes [%ld] and [%ld]\n", curr->index,
			temp->index);
	/*loop to search*/
	while (curr && curr->index < temp->index && curr->n < value)
	{
		printf("Value checked at index [%ld] = [%d]\n", curr->index,
				curr->n);
		curr = curr->next;
	}
	printf("Value checked at index [%ld] = [%d]\n", curr->index, curr->n);
	if (curr->n == value)
	{
		return (curr);
	}
	return (NULL);
}
