#include "main.h"
#include <stdio.h>
#include <ctype.h>
/**
 * print_buffer - prints a buffer
 * @b: parmeter to be used
 * @size: parameter to be used
 * Return: void
 */
void print_buffer(char *b, int size)
{
	int op, jp, ip;

	op = 0;
	if (size <= 0)
	{
		printf("\n");
		return;
	}
	while (op < size)
	{
		jp = size - op < 10 ? size - op : 10;
		printf("%08x: ", op);
		for (ip = 0; ip < 10; ip++)
		{
			if (ip < jp)
				printf("%02x", *(b + op + ip));
			else
				printf("  ");
			if (ip % 2)
			{
				printf(" ");
			}
		}
		for (ip = 0; ip < jp; ip++)
		{
			int c = *(b + op + ip);

			if (c < 32 || c > 132)
			{
				c = '.';
			}
			printf("%c", c);
		}
		printf("\n");
		op += 10;
	}
}
