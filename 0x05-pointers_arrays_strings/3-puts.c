#include "main.h"
#include <stdio.h>

/**
 * _puts - prints a string, followed by \n
 * @str: pointer
 * Return: nothing
 */

void _puts(char *str)
{
	int i = 0;

	while (*(str + i))
	{
		puts(str);
		i--;
	}
}
