#include "main.h"
#include <ctype.h>
/**
 * _isdigit - checks for a digit
 * @c: char to be checked
 * Return: 0
 */
int _isdigit(int c)
{
	if (isdigit(c) != 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
