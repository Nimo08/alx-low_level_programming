#include "main.h"
#include <stdio.h>
/**
 * reverse_array - reverses content of an array
 * @a: pointer
 * @n: number of elements
 * Return: nothing
 */
void reverse_array(int *a, int n)
{
	int i, temp;
	int mid = n / 2;

	for (i = 0; i < mid; i++)
	{
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}
