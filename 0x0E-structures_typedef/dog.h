#ifndef DOG_H
#define DOG_H
/**
 * struct dog - new struct dog
 * @name: char pointer
 * @age: float  var
 * @owner: char pointer
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
/**
 * init_dog - initializes a variable of type struct dog
 * @d: struct pointer
 * @name: char pointer
 * @age: float var
 * @owner: char pointer
 */
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif
