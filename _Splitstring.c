#include "main.h"
/**
 * _splitstring - counts number of words in string
 * @str: pointer to string to count
 *
 * Return: number of words in string
 */
int _splitstring(char *str)
{
	int j, searchmap = 1, alphacount = 0;

	for (j = 0; str[j]; j++)
	{
		if (str[j] != ' ' && searchmap == 1)
		{
			alphacount += 1;
			searchmap = 0;
		}
		if (str[j + 1] == ' ')
			searchmap = 1;
	}
	return (alphacount);
}