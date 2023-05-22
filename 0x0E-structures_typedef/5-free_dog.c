#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * free_dog - frees the space allocated
 * @d: pointer
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
	{
		return;
	}
	free(d->name);
	free(d->owner);
	free(d);
}
