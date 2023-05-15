#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
/**
 * str_concat - concatenates two strings
 * @s1: char pointer
 * @s2: char pointer
 * Return: pointer to concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	int i;
	char *s3;
	int len1;
	int len2;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	len1 = strlen(s1);
	len2 = strlen(s2);

	s3 = (char *) malloc(len1 + len2 + 1);
	if (s3 == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len1; i++)
	{
		s3[i] = s1[i];
	}
	for (i = 0; i < len2; i++)
	{
		s3[len1 + i] = s2[i];
	}
	s3[len1 + len2] = '\0';
	return (s3);
}
