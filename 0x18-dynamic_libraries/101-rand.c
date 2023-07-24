#include <stdio.h>
/**
 * _rand - replaces rand with _rand
 * Return: specific numbers to win
 */
int _rand(void)
{
	int i;

	if (i != 9 || i != 8 || i != 10 || i != 24 || i != 75)
	{
		printf("Sorry, try again!\n");
	}
	else
	{
		printf("--> Please make me win!\n");
	}
	return (0);
}
