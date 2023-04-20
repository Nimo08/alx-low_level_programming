#include<stdio.h>
/**
 * main - Entry point
 * Description: prints sizes of various data types
 * Return: Always 0 (Success)
 */

int main(void)
{
	char c;
	int i;
	long int j;
	long long int k;
	float f;

	printf("Size of a char: %d byte(s)", sizeof(c));
	printf("Size of an int: %d byte(s)", sizeof(i));
	printf("Size of a long int: %ld byte(s)", sizeof(j));
	printf("Size of a long long int: %ld byte(s)", sizeof(k));
	printf("Size of a float: %f byte(s)", sizeof(f));
	return (0);
}
