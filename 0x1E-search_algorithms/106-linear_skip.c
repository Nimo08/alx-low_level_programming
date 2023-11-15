#include "search_algos.h"
#include <stdio.h>
#include <math.h>
/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: return a pointer on the first node where value is located
 * If value is not present in list or if head is NULL,
 * your function must return NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *curr, *temp;

	if (list == NULL)
	{
		return (NULL);
	}
	curr = temp = list;
	/*move to next node*/
	while (temp->next != NULL && temp->n < value)
	{
		/*store value of temp*/
		curr = temp;
		/*check the express lane*/
		if (temp->express != NULL)
		{
			temp = temp->express;
			printf("Value checked at index [%ld] = [%d]\n", temp->index, temp->n);
		}
		else
		{
			/*check normal lane*/
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
		}
	}
	printf("Value found between indexes [%ld] and [%ld]\n", curr->index,
			temp->index);
	/*check gap between curr and temp*/
	while (curr->index < temp->index && curr->n < value)
	{
		printf("Value checked at index [%ld] = [%d]\n", curr->index, curr->n);
		curr = curr->next;
	}
	printf("Value checked at index [%ld] = [%d]\n", curr->index, curr->n);
	if (curr->n == value)
		return (curr);
	return (NULL);
}
