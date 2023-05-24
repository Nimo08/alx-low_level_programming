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
	unsigned char main_opc[] = {0xf3, 0x0f, 0x1e, 0xfa, 0x31, 0xed, 0x49, 0x89,
		0xd1, 0x5e, 0x49, 0x89, 0xe2, 0x48, 0x89, 0xe2, 0x48,
		0x83, 0xe4, 0xf0, 0x50};
	unsigned char *op_ptr;
	unsigned int i;
	unsigned int size;
	unsigned int range;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	size = atoi(argv[1]);
	range = size;
	if (size < 0)
	{
		printf("Error\n");
		exit(2);
	}
	op_ptr = main_opc;
	for (i = 0; i < range; i++)
	{
		printf("%02x ", op_ptr[i]);
	}
	printf("\n");
	return (0);
}
