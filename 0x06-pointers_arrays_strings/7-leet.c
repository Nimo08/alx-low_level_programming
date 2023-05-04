#include "main.h"
#include <stdio.h>
/**
 * leet - encodes a string
 * @s: pointer
 * Return: encoded string
 */
char *leet(char *s)
{
	int i, j;
	char x[] = "4433007711";
	char y[] = "aAeEoOtTlL";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; y[j] != '\0'; j++)
		{
			if (s[i] == y[j])
			{
				s[i] = x[j];
				break;
			}
		}
	}
	return (s);
}
