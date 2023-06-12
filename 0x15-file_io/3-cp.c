#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
 * main - copies content of a file to another file
 * @ac: argument count
 * @av: argument vector
 * Return: 0
 */
int main(int ac, char **av)
{
	int file_to, file_from;
	char buf[BUF];
	int read_data = 0, write_data = 0;

	if (ac != 3)
	{
		error_usage();
	}
	file_from = open(av[1], O_RDONLY);
	if (file_from == -1)
	{
		read_error(av[1]);
	}
	file_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
	{
		write_error(av[2]);
	}
	while ((read_data = read(file_from, buf, BUF)) > 0)
	{
		write_data = write(file_to, buf, read_data);
		if (write_data == -1 || write_data != read_data)
		{
			write_error(av[2]);
		}
	}
	if (read_data == -1)
	{
		read_error(av[1]);
	}
	if (close(file_from) == -1)
	{
		close_error(file_from);
	}
	if (close(file_to) == -1)
	{
		close_error(file_to);
	}
	return (0);
}
