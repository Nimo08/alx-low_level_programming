#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * hash_table_create - creates a hash table
 * @size: size of the array
 * Return: pointer to newly created hash table, or NULL
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table_ptr;
	unsigned int i;

	table_ptr = malloc(sizeof(hash_table_t));
	if (table_ptr == NULL)
	{
		return (NULL);
	}
	table_ptr->array = malloc(sizeof(hash_node_t *) * size);
	if (table_ptr->array == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		table_ptr->array[i] = NULL;
	}
	return (table_ptr);
}
