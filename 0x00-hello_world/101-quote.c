#include<stdio.h>
#include<unistd.h>
/**
 * main - Entry point
 * Description: printing to standard error without printf and puts
 * Return: 1
 */
int main(void)
{
	write(1, "and that is a piece of art is useful\" - Dora Korpar, 2015-10-19\n", 50);
	return (1);
}
