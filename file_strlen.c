#include "main.h"
/**
 * _strlen - returns the length of a string
 * @s: character type
 * i - integer type
 * Return: integer type
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}