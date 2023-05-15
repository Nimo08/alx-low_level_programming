#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
/**
 * _strdup - returns a pointer to a new string which is a duplicate of
 * the string str
 * @str: char pointer
 * Return: pointer to duplicated string, or NULL
 */
char *_strdup(char *str)
{
	unsigned int i;
	char *duplicate;

	duplicate = (char *) malloc(strlen(str) + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < strlen(str); i++)
	{
		duplicate[i] = str[i];
	}
	return (duplicate);
}
