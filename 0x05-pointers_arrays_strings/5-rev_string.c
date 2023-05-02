#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * rev_string(char *s) - reverses a string
 * @s: pointer
 * Return: nothing
 */
void rev_string(char *s)
{
	int i;
	char temp;
	int len = strlen(s);
	int mid = len / 2;

	for (i = 0; i < mid; i++)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}
