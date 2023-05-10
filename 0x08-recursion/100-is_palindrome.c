#include "main.h"
#include <stddef.h>
#include <string.h>
/**
 * is_palindrome - checks if string is a palindrome
 * @s: char pointer
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len;

	if (s == NULL)
	{
		return (0);
	}
	len = strlen(s);
	return (palindrome_helper(s, 0, len - 1));
}
/**
 * palindrome_helper - checks if string is a palindrome
 * @s: char pointer
 * @i: int
 * @j: int
 * Return: 1 if palindrome, 0 otherwise
 */
int palindrome_helper(char *s, int i, int j)
{
	if (s == NULL || i < 0 || j < 0)
	{
		return (0);
	}
	if (i >= j)
	{
		return (1);
	}
	if (s[i] == s[j])
	{
		return (palindrome_helper(s, i + 1, j - 1));
	}
	return (0);
}
