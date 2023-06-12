#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BUF 1024
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
	int read_data = 0;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s cp file_from file_to\n", av[0]);
		exit(97);
	}
	file_from = open(av[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	file_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", av[2]);
		exit(99);
	}
	while ((read_data = read(file_from, buf, BUF)) > 0)
	{
		if (write(file_to, buf, read_data) == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", av[2]);
			exit(99);
		}
	}
	if (read_data == -1)
	{
		dprintf(STDERR_FILENO, "Can't read from file %s\n",  av[1]);
		exit(98);
	}
	if (close(file_from) == -1 || close(file_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd value\n");
		exit(100);
	}
	return (0);
}
