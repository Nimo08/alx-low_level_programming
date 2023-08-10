#include "hash_tables.h"
#include <stdio.h>
/**
 * key_index - gives the index of a key
 * @key: key
 * @size: size of the array of the hash table
 * Return: index at which the key/value should be stored
 * in the array of the hash table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned int hash, index;

	hash = hash_djb2(key);
	index = hash % size;
	return (index);
}
