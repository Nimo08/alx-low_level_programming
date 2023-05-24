#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - check the code
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *op = argv[2];
	int num1, num2;
	int res;
	int (*op_func)(int, int) = get_op_func(op);

	res = 0;
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	if (op_func == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	if (num2 == 0 && (op[0] == '/' || op[0] == '%'))
	{
		printf("Error\n");
		exit(100);
	}
	res =  op_func(num1, num2);
	printf("%d\n", res);
	return (0);
}
