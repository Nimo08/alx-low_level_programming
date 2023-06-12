#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BUF 1024
/**
 * exit_error - exits with an error
 * @msg: error message
 * @av1: arg 1
 * @code: exit code
 */
void exit_error(const char *msg, const char *av1, int code)
{
	dprintf(STDERR_FILENO, msg, av1);
	exit(code);
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
		exit_error("Usage: %s cp file_from file_to\n", av[0], 97);
	}
	file_from = open(av[1], O_RDONLY);
	if (file_from == -1)
	{
		exit_error("Error: Can't read from file %s\n", av[1], 98);
	}
	file_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
	{
		close(file_from);
		exit_error("Error: Can't write to file %s\n", av[2], 99);
	}
	while ((read_data = read(file_from, buf, BUF)) > 0)
	{
		write_data = write(file_to, buf, read_data);
		if (write_data == -1 || write_data != read_data)
		{
			close(file_from);
			close(file_to);
			exit_error("Error: Can't write to file %s\n", av[2], 99);
		}
	}
	if (read_data == -1)
	{
		close(file_from);
		close(file_to);
		exit_error("Can't read from file %s\n", av[1], 98);
	}
	if (close(file_from) == -1 || close(file_to) == -1)
	{
		exit_error("Error: Can't close fd value\n", "", 100);
	}
	return (0);
}
