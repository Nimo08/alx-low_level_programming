#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
/**
 * append_text_to_file - appends text at the end of a line
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file;
	int len = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	file = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0664);
	if (file == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		len = strlen(text_content);
	}
	if (write(file, text_content, len) == -1)
	{
		close(file);
		return (-1);
	}
	close(file);
	return (1);
}
