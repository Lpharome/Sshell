#include "main.h"
/**
 * _PATHstrcmp - compares PATH with environ to find PATH value
 * @s1: pointer PATH string
 * @s2: pointer to environ string with actual value
 *
 * Return: 0 on success
 */
int _PATHstrcmp(const char *s1, const char *s2)
{
	int j;

	for (j = 0; s2[j] != '='; j++)
	{
		if (s1[j] != s2[j])
			return (-1);
	}
	return (0);
}