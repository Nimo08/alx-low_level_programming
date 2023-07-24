#include "main.h"
#include <ctype.h>
/**
 * _isalpha - entry point
 * @c: char to be checked
 * Description: checks for alphabetic character
 * Return: 1 if c is a letter, 0 otherwise
 */
int _isalpha(int c)
{
	if (isalpha(c) != 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
