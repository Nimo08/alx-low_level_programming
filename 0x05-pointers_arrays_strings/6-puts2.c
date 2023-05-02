#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * puts2 - prints every other character of a string
 * @str: pointer
 * Return: nothing
 */
void puts2(char *str)
{
	int i;
	int len = strlen(str);

	for (i = 0; i < len; i += 2)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
