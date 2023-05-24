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
	unsigned int count = 0;
	unsigned int size;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	size = atoi(argv[1]);
	if (size < 0)
	{
		printf("Error\n");
		exit(2);
	}
	while (count < size)
	{
		printf("%02x", *((unsigned char *)main + count));
		count++;
		if (size > count)
		{
			printf(" ");
		}
	}
	printf("\n");
	return (0);
}
