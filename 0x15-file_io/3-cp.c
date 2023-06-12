#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BUF 1024
void exit_error(const char *msg, const char *av1, int code);
int file1(const char *filename);
int file2(const char *filename);
void file_copy(int f1, int f2);
void file_close(int file);
/**
 * main - copies content of a file to another file
 * @ac: argument count
 * @av: argument vector
 * Return: 0
 */
int main(int ac, char **av)
{
	int file_to, file_from;

	if (ac != 3)
	{
		exit_error("Usage: %s cp file_from file_to\n", av[0], 97);
	}
	file_from = file1(av[1]);
	file_to = file2(av[2]);
	file_copy(file_from, file_to);
	file_close(file_from);
	file_close(file_to);
	return (0);
}
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
 * file1 - opens first file
 * @filename: file name
 * Return: file_from
 */
int file1(const char *filename)
{
	int f1;

	f1 = open(filename, O_RDONLY);
	if (f1 == -1)
	{
		exit_error("Error: Can't read from file %s\n", filename, 98);
	}
	return (f1);
}
/**
 * file2 - opens second file
 * @filename: file name
 * Return: file_to
 */
int file2(const char *filename)
{
	int f2;

	f2 = open(filename, O_WRONLY, O_CREAT | O_TRUNC, 0664);
	if (f2 == -1)
	{
		exit_error("Error: Can't write to file %s\n", filename, 99);
	}
	return (f2);
}
/**
 * file_copy - copies f1 to f2
 * @f1: source file
 * @f2: destination file
 * Return: nothing
 */
void file_copy(int f1, int f2)
{
	char buf[BUF];
	int read_data, write_data;

	while ((read_data = read(f1, buf, BUF)) > 0)
	{
		write_data = write(f2, buf, read_data);
		if (write_data == -1 || write_data != read_data)
		{
			exit_error("Error: Can't write to file\n", "", 99);
		}
	}
	if (read_data == -1)
	{
		exit_error("Can't read from file\n", "", 98);
	}
}
/**
 * file_close - closes file
 * @file: file
 * Return: nothing
 */
void file_close(int file)
{
	if (close(file) == -1)
	{
		exit_error("Error: Can't close fd value\n", "", 100);
	}
}
