#include "search_algos.h"
#include <stdio.h>
int advanced_helper(int *array, size_t l, size_t r, int value);
/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: return the index where value is located
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
	{
		return (-1);
	}
	return (advanced_helper(array, 0, size - 1, value));
}
/**
 * advanced_helper - helper function
 * @array: pointer to the first element of the array to search in
 * @l: left-most element
 * @r: right-most element
 * @value: value to search for
 * Return: return the index where value is located
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int advanced_helper(int *array, size_t l, size_t r, int value)
{
	size_t mid, i;

	if (l > r)
	{
		return (-1);
	}
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
	mid = (l + r) / 2;
	if (array[mid] == value)
	{
		if (mid == 0 || array[mid - 1] != value)
		{
			/*first occurrence*/
			return (mid);
		}
		/*continue searching left*/
		return (advanced_helper(array, l, mid, value));
	}
	else if (array[mid] > value)
	{
		return (advanced_helper(array, l, mid - 1, value));
	}
	else
	{
		return (advanced_helper(array, mid + 1, r, value));
	}
}
