#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * shash_table_create - create hash table
 * @size: size of the array
 * Return: pointer to newly created hash table, or NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	unsigned long int index;

	table = malloc(sizeof(shash_table_t));
	if (table == NULL)
	{
		return (NULL);
	}
	table->size = size;
	table->array = malloc(sizeof(shash_node_t) * size);
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	for (index = 0; index < table->size; index++)
	{
		table->array[index] = NULL;
	}
	table->shead = NULL;
	table->stail = NULL;
	return (table);
}
/**
 * create_shash_node - creates a node
 * @key: the key
 * @value: value corresponding to the key
 * Return: new node
 */
shash_node_t *create_shash_node(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
	{
		return (NULL);
	}
	node->key = strdup(key);
	node->value = strdup(value);
	node->next = NULL;
	node->sprev = NULL;
	node->snext = NULL;
	return (node);
}
/**
 * shash_table_set - insert key/value pair
 * @ht: hash table
 * @key: the key
 * @value: value corresponding to the key
 * Return: 1 if it succeeds, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *ptr;
	unsigned long int index = 0;

	if (ht == NULL || ht->array == NULL || key == NULL || value == NULL)
	{
		return (0);
	}
	ptr = create_shash_node(key, value);
	if (ptr == NULL)
	{
		return (0);
	}
	index = hash_djb2((const unsigned char *)key) % ht->size;

	if (ht->array[index] == NULL)
	{
		ht->array[index] = ptr;
	}
	else if (strcmp(ht->array[index]->key, key) == 0)
	{
		free(ht->array[index]->value);
		free(ptr->key);
		free(ptr->value);
		free(ptr->sprev);
		free(ptr->snext);
		free(ptr);
		ht->array[index]->value = strdup(value);
		return (1);
	}
	else
	{
		ptr->next = ht->array[index];
		ht->array[index] = ptr;
	}
	return (1);
}
/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: hash table to look into
 * @key: key to look for
 * Return: value associated with the element,
 * or NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index = 0;

	if (ht == NULL || ht->array == NULL || key == NULL)
	{
		return (NULL);
	}
	index = hash_djb2((const unsigned char *)key) % ht->size;
	if (ht->array[index] != NULL)
	{
		if (strcmp(ht->array[index]->key, key) == 0)
		{
			return (ht->array[index]->value);
		}
	}
	return (NULL);
}
/**
 * shash_table_print - prints hash table
 * @ht: hash table
 * Return: nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *ptr;
	unsigned long int index = 0, flag = 0;

	if (ht == NULL || ht->array == NULL)
	{
		return;
	}
	printf("{");
	for (index = 0; index < ht->size; index++)
	{
		ptr = ht->array[index];
		while (ptr != NULL)
		{
			if (flag)
			{
				printf(", ");
			}
			printf("'%s': '%s'", ptr->key, ptr->value);
			flag = 1;
			ptr = ptr->next;
		}
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - prints hash table in reverse
 * @ht: hash table
 * Return: nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *ptr;
	unsigned long int index = 0, flag = 0;

	if (ht == NULL || ht->array == NULL)
	{
		return;
	}
	printf("{");
	for (index = ht->size - 1; index > 0; index--)
	{
		ptr = ht->array[index];
		while (ptr != NULL)
		{
			if (flag)
			{
				printf(", ");
			}
			printf("'%s': '%s'", ptr->key, ptr->value);
			flag = 1;
			ptr = ptr->next;
		}
	}
	printf("}\n");
}

/**
 * free_shash_node - frees node
 * @node: pointer
 * Return: nothing
 */
void free_shash_node(shash_node_t *node)
{
	free(node->key);
	free(node->value);
	free(node->sprev);
	free(node->snext);
	free(node);
}
/**
 * shash_table_delete - deletes hash table
 * @ht: hash table
 * Return: nothing
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *ptr, *temp;
	unsigned long int index;

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
			free_shash_node(ptr);
			ptr = temp;
		}
	}
	free(ht->array);
	free(ht);
}
