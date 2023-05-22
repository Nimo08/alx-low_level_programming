#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * init_dog - initialize variable of type struct dog
 * @d: struct
 * @name: char pointer
 * @age: float var
 * @owner: char pointer
 * Return: nothing
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;
	d->name = name;
	d->age = age;
	d->owner = owner;

}
