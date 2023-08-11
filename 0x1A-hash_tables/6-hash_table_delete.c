#include "hash_tables.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * free_node - frees the node
 * @node: pointer
 * Return: nothing
 */
void free_node(hash_node_t *node)
{
	free(node->key);
	free(node->value);
	free(node);
}
/**
 * hash_table_delete - deletes a hash table
 * @ht: hash table
 * Return: nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *ptr, *temp;
	unsigned long int index = 0;

	if (ht == NULL || ht->array == NULL)
	{
		return;
	}
	for (index = 0; index < ht->size; index++)
	{
		ptr = ht->array[index];
		while (ptr != NULL)
		{
			temp = ptr->next;
			free_node(ptr);
			ptr = temp;
		}
	}
	free(ht->array);
	free(ht);
}
