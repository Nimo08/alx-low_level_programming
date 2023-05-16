#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
/**
 * argstostr - concatenates all program arguments
 * @ac: int
 * @av: char pointer to pointer
 * Return: pointer to new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *str = "";
	int i;
	int j;
	int k = 0;
	int len = 0;
	int len1 = 0;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < ac; i++)
	{
		len += strlen(av[i]) + 1;
	}
	str = (char *) malloc(sizeof(char) * len);
	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < ac; i++)
	{
		len1 = strlen(av[i]);
		for (j = 0; j < len1; j++)
		{
			str[k++] =  av[i][j];
		}
		str[k++] = '\n';
	}
	str[k] = '\0';
	return (str);
}
