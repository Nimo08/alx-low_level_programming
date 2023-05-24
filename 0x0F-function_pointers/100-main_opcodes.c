#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints opcodes
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int count;
	int size;

	size = atoi(argv[1]);
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	if (size < 0)
	{
		printf("Error\n");
		exit(2);
	}
	for (count = 0; count < size; count++)
	{
		printf("%02x", *((unsigned char *)main + count));
		if (size > count)
		{
			printf(" ");
		}
	}
	printf("\n");
	return (0);
}
