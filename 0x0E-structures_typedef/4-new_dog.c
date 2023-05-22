#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * new_dog - creates a new dog
 * @name: char pointer
 * @age: float var
 * @owner: char pointer
 * Return: pointer to dog_t
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	int i;
	int len_name;
	int len_owner;

	dog_t *new_dog;

	if (name == NULL || owner == NULL)
		return (NULL);
	len_name = strlen(name);
	len_owner = strlen(owner);
	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);
	new_dog->name = malloc(len_name + 1);
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}
	new_dog->owner = malloc(len_owner + 1);
	if (new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}

	for (i = 0; i < len_name; i++)
	{
		new_dog->name[i] = name[i];
	}
	new_dog->name[len_name] = '\0';
	for (i = 0; i < len_owner; i++)
	{
		new_dog->owner[i] = owner[i];
	}
	new_dog->owner[len_owner] = '\0';
	new_dog->age = age;

	return (new_dog);
}
