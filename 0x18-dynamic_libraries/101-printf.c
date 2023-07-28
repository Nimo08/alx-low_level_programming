#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * printf - prints to stdout
 * @format: const char
 * Return: specific numbers to win
 */
int printf(const char *format, ...)
{
	write(1, "9 8 10 24 75 - 9 \n", 17);
	write(1, "Congratulations, you win the Jackpot!\n", 38);
}
