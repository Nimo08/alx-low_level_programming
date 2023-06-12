#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_ptr;
	int len;

	len = strlen(text_content);
	if (filename == NULL)
	{
		return (-1);
	}
	file_ptr = open(filename, O_WRONLY | O_CREAT | O_TRUNC);
	chmod(filename, 0600);
	if (file_ptr == -1)
	{
		return (-1);
	}
	write(file_ptr, text_content, len);
	close(file_ptr);
	return (1);
}
