#include "search_algos.h"
#include <stdio.h>
int binarysearch(int *array, int l, int r, int value);
int min(int x, int y);
/**
 * exponential_search - searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: return the first index where value is located
 * If value is not present in array or if array is NULL
 * your function must return -1
 */
int exponential_search(int *array, size_t size, int value)
{
	int bound = 1;

	if (array == NULL)
	{
		return (-1);
	}
	while (bound < (int)size && array[bound] < value)
	{
		printf("Value checked array[%d] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}
	printf("Value found between indexes [%d] and [%d]\n", bound / 2,
			min(bound, size - 1));
	return (binarysearch(array, bound / 2, min(bound, size - 1), value));
}
/**
 * binarysearch - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @l: left-most element
 * @r: right-most element
 * @value: value to search for
 * Return: return the index where value is located
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int binarysearch(int *array, int l, int r, int value)
{
	int mid, i;

	if (array == NULL)
	{
		return (-1);
	}
	while (l <= r)
	{
		mid = (l + r) / 2;
		printf("Searching in array: ");
		for (i = l; i <= r; i++)
		{
			if (i != l)
			{
				printf(", ");
			}
			printf("%d", array[i]);
		}
		printf("\n");
		if (array[mid] == value)
		{
			return (mid);
		}
		else if (array[mid] < value)
		{
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return (-1);

}
/**
 * min - find minimum value
 * @x: int
 * @y: int
 * Return: min value
 */
int min(int x, int y)
{
	return ((x < y) ? x : y);
}
