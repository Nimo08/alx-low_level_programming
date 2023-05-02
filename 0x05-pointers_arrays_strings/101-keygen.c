#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random valid passwords for
 * the program 100-crackme
 * Return: Always 0
 */
int main(void)
{
	int pass[100];
	int i, result, j;

	result = 0;

	srand(time(NULL));

	for (i = 0; i < 100; i++)
	{
		pass[i] = rand() % 78;
		result += (pass[i] + '0');
		putchar(pass[i] + '0');

		if ((2772 - result) - '0' < 78)
		{
			j = 2772 - result - '0';
			result += j;
			putchar(j + '0');
			break;	       
		}
	}
	return (0);
}
