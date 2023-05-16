#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
/**
 * get_word_count - Counts the number of words in a string.
 * @str: char pointer
 *
 * Return: The number of words.
 */
int get_word_count(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;

		if (str[i] != '\0')
		{
			count++;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
	}

	return (count);
}
/**
 * strtow - returns a pointer to an array of strings
 * @str: char pointer
 * Return: pointer to an array pf strings
 */
char **strtow(char *str)
{
	int k;
	int word_count, i, j, word_start, word_end, word_length;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);
	word_count = get_word_count(str);
	if (word_count == 0)
		return (NULL);

	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0' && j < word_count)
	{
		while (str[i] == ' ')
			i++;
		word_start = i;
		while (str[i] != ' ' && str[i] != '\0')
			i++;
		word_end = i;
		word_length = word_end - word_start;
		words[j] = malloc((word_length + 1) * sizeof(char));
		if (words[j] == NULL)
		{
			for (i = 0; i < j; i++)
				free(words[i]);
			free(words);
			return (NULL);
		}
		for (k = 0; k < word_length; k++)
			words[j][k] = str[word_start + k];
		words[j][word_length] = '\0';
		j++;
	}
	words[j] = NULL;
	return (words);
}
