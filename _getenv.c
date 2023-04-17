#include "main.h"
/**
 * _getenv - gets PATH member from environ
 * @name: pointer to PATH string
 *
 * Return: pointer to PATH member string or NULL if not found
 */
char *_getenv(const char *name)
{
	int i, result;

	for (i = 0; envi[i]; i++)
	{
		result = _PATHstrcmp(name, envi[i]);
		if (result == 0)
		{
			return (envi[i]);
		}
	}
	return (NULL);
}
