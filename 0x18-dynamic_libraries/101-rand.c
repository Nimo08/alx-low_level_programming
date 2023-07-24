#include <stdio.h>
#include <stdlib.h>
/**
 * _rand - replaces rand with _rand
 * Return: specific numbers to win
 */
int _rand(void)
{
	int i = rand();

	if (i == 9 || i == 8 || i == 10 || i == 24 || i == 75)
	{
		printf("--> Please make me win!\n");
	}
	else
	{
		printf("Sorry, try again!\n");
	}
	return (i);
}
