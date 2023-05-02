#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * puts_half - prints half of a string
 * @str: pointer
 * Return: nothing
 */
void puts_half(char *str)
{
	int i;
	int n = strlen(str);

	for (i = 0; str[i] != '\0'; i++)
	{
		for (i = n / 2; i < n; i++)
		{
			_putchar(str[i]);
		}
	}
	_putchar('\n');
}
