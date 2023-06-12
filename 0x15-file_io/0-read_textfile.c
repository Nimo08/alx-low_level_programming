#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
/**
 * read_textfile - reads a text file and prints it to the POSIX stdout
 * @filename: file name
 * @letters: number of letters it should read and print
 * Return: actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *read_ptr;
	char *letters_buf;
	size_t num_letters = 0;
	size_t rem_letters = letters;
	size_t len;

	if (filename == NULL)
	{
		return (0);
	}
	read_ptr = fopen(filename, "r");
	if (read_ptr != NULL)
	{
		letters_buf = malloc(letters + 1);
		if (letters_buf == NULL)
		{
			fclose(read_ptr);
			return (0);
		}
		while (fgets(letters_buf, letters + 1, read_ptr) != NULL)
		{
			len = strlen(letters_buf);
			if (rem_letters < len)
			{
				len = rem_letters;
			}
			write(STDOUT_FILENO, letters_buf, len);
			num_letters += len;
			rem_letters -= len;
			if (rem_letters <= 0)
			{
				break;
			}
		}
		fclose(read_ptr);
		free(letters_buf);
		return (num_letters);
	}
	return (0);
}
