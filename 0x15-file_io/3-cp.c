#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BUF 1024
void error_usage(void);
void read_error(const char *filename);
void write_error(const char *filename);
void close_error(int file);
/**
 * error_usage - displays usage error message
 */
void error_usage(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}
/**
 * read_error - read error message
 * @filename: name of file
 * Return: nothing
 */
void read_error(const char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	exit(98);
}
/**
 * write_error - write error message
 * @filename: name of file
 * Return: nothing
 */
void write_error(const char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", filename);
	exit(99);
}
/**
 * close_error - close error message
 * @file: file
 */
void close_error(int file)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd value %d\n", file);
	exit(100);
}
/**
 * file_copy - copies content of file1 to file2
 * @file1: file to be copied from
 * @file2: file to get the copied content
 */
void file_copy(const char *file1, const char *file2)
{
	int file_to, file_from;
	char buf[BUF];
	int read_data = 0, write_data = 0;

	file_from = open(file1, O_RDONLY);
	if (file_from == -1)
	{
		read_error(file1);
	}
	file_to = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
	{
		write_error(file2);
	}
	while ((read_data = read(file_from, buf, BUF)) > 0)
	{
		write_data = write(file_to, buf, read_data);
		if (write_data == -1 || write_data != read_data)
		{
			write_error(file2);
		}
	}
	if (read_data == -1)
	{
		read_error(file1);
	}
	if (close(file_from) == -1)
	{
		close_error(file_from);
	}
	if (close(file_to) == -1)
	{
		close_error(file_to);
	}
}
/**
 * main - copies content of a file to another file
 * @ac: argument count
 * @av: argument vector
 * Return: 0
 */
int main(int ac, char **av)
{
	if (ac != 3)
	{
		error_usage();
	}
	file_copy(av[1], av[2]);

	return (0);
}
