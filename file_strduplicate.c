#include "main.h"
/**
 * _strdup - duplicates a string
 * @str: pointer to string to duplicate
 *
 * Return: pointer to duplicated string
 */
char *_strdup(char *str)
{
	int j;
	char *str_1 = NULL;

	if (str == NULL)
		return (NULL);
	for (j = 0; str[j] != '\0'; j++)
		;
	str_1 = malloc(sizeof(char) * (j + 1));
	if (str_1 == NULL)
		return (NULL);
	for (j = 0; str[j] != '\0'; j++)
	{
		str_1[j] = str[j];
	}
	str_1[j] = '\0';
	return (str_1);
}