#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * string_nconcat - concatenates 2 strings
 * @s1: char pointer
 * @s2: char pointer
 * @n: unsigned int
 * Return: pointer
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	char *s3;
	unsigned int len1;
	unsigned int len2;

	len1 = strlen(s1);
	len2 = strlen(s2);

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	s3 = malloc(len1 + n + 1);
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
	s3[len1 + n] = '\0';
	return (s3);
}
