#include "main.h"
#include <stdlib.h>
/**
 * _abs - entry point
 * @x: int to be checked
 * Description: computes absolute value
 * Return: Always 0
 */
int _abs(int x)
{
	if (x >= 0)
	{
		return (x);
	}
	else
	{
		return (-x);
	}
}
