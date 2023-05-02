#include "main.h"
/**
 * _atoi - convert string to integer
 * @s: pointer
 * Return: int
 */
int _atoi(char *s)
{
	int sign = 1;
	int num = 0;

	while (*s == ' ')
	{
		s++;
	}
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
	{
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s - '0');
		s++;
	}
	return (sign * num);
}
