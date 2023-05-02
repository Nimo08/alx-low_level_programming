#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * _strlen - returns length of string
 * @s: char
 * Return: len
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i))
	{
		i++;
	}
	return (i);
}
