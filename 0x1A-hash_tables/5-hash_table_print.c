#include "hash_tables.h"
#include <stdio.h>
/**
 * hash_table_print - prints a hash table
 * @ht: hash table
 * Return: nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index = 0;
	unsigned long int flag = 0;

	if (ht == NULL)
	{
		return;
	}
	printf("{");
	for (index = 0; index < ht->size; index++)
	{
		if (ht->array[index] != NULL)
		{
			if (flag)
			{
				printf(", ");
			}
			printf("'%s': '%s'", ht->array[index]->key, ht->array[index]->value);
			flag = 1;
		}
	}
	printf("}\n");
}
