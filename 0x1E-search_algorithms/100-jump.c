#include "search_algos.h"
#include <stdio.h>
#include <math.h>
/**
 * jump_search - searches for a value in a sorted array of integers
 * using the Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size:  number of elements in array
 * @value: value to search for
 * Return: return the first index where value is located
 * If value is not present in array or if array is NULL
 * your function must return -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, start, end;

	start = 0, end = sqrt(size);
	if (array == NULL)
	{
		return (-1);
	}
	printf("Value checked array[%ld] = [%d]\n", start, array[start]);
	while (array[end] < value && end < size)
	{
		printf("Value checked array[%ld] = [%d]\n", end, array[end]);
		start = end;
		end += sqrt(size);
	}
	printf("Value found between indexes [%ld] and [%ld]\n", start, end);
	if (end > size - 1)
	{
		end = size - 1;
	}
	for (i = start; i <= end; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}
	return (-1);
}
