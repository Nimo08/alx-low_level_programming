#include "main.h"
#include <stddef.h>
/**
 * _strchr - locates a character in a string
 * @s: pointer
 * @c: char
 * Return: pointer to first occurrence of c
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}
