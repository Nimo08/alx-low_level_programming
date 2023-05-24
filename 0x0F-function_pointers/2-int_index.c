#include "function_pointers.h"
/**
 * cmp_func - comparison function
 * @a: int var
 * @cmp: function pointer
 * Return: result var
 */
int cmp_func(int a, int (*cmp)(int))
{
	int res;

	res = cmp(a);
	return (res);
}
/**
 * int_index - searches for an integer
 * @array: int pointer
 * @size: int var
 * @cmp: function pointer
 * Return: index of first element for which cmp
 * function does not return 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array != NULL && cmp != NULL)
	{
		if (size <= 0)
		{
			return (-1);
		}
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
			{
				return (i);
			}
		}
	}
	return (-1);
}
