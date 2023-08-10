#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * create_node - creates a node
 * @key: the key, string
 * @value: value corresponding to a key
 * Return: new node
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node, *ptr = NULL;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
	{
		return (NULL);
	}
	node->key = strdup(key);
	node->value = strdup(value);
	node->next = ptr;
	return (node);
}
/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table you want to add/update the key/value to
 * @key: the key
 * @value: value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *ptr;
	unsigned long int index = 0;

	if (ht == NULL || ht->array == NULL)
	{
		return (0);
	}
	ptr = create_node(key, value);
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
		strcpy(ht->array[index]->value, value);
	}
	else
	{
		ptr->next = ht->array[index];
		ht->array[index] = ptr;
	}
	return (1);
}
