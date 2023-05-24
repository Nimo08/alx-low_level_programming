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
	unsigned char *op_ptr;
	unsigned int i;
	unsigned int size;
	unsigned int range;

	size = atoi(argv[1]);
	range = size * 1;
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
	for (i = 0; i < range && op_ptr[i] != '\0'; i++)
	{
		printf("%02x ", op_ptr[i]);
	}
	printf("\n");
	return (0);
}
