#include "main.h"
#include <ctype.h>
/**
 * _islower - entry point
 * @c: char to be checked
 * Description: checks for lowercase
 * Return: 1 if lowercase, 0 otherwise.
 */
int _islower(int c)
{
	if (islower(c) != 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
