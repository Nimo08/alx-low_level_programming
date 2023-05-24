#include "function_pointers.h"
/**
 * print_name - prints a name
 * @name: char pointer
 * @f: function pointer
 * @char *: char pointer
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
