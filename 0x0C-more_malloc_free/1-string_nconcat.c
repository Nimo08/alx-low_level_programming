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
	unsigned int i = 0;
	unsigned int j = 0;
	char *s3;
	unsigned int len1 = 0;
	unsigned int len2 = 0;


	while (s1 && s1[len1])
	{
		len1++;
	}
	while (s2 && s2[len2])
	{
		len2++;
	}
	if (n < len2)
	{
		s3 = malloc(sizeof(char) * (len1 + n + 1));
	}
	else
	{
		s3 = malloc(sizeof(char) * (len1 + len2 + 1));
	}
	if (!s3)
	{
		return (NULL);
	}
	while (i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	while (n < len2 && i < (len1 + n))
	{
		s3[i++] = s2[j++];
	}
	while (n >= len2 && (len1 + len2))
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}
