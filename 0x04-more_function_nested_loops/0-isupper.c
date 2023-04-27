#include "main.h"
#include <ctype.h>
/**
 * _isupper - checks for uppercase aletter
 * @c: char to be checked
 * Return: 0
 */
int _isupper(int c)
{
	if (isupper(c) != 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
