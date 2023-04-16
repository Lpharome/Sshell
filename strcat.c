#include "main.h"
/**
 * _concat - concats user string with PATH member string and /
 * @tmp: static array to store concatenated string
 * @av: pointer to array of user strings
 * @tok: pointer to PATH token
 *
 * Return: 0 on success
 */
char *_concat(char *tmp, char **avg, char *tokeen)
{
    char *tmp;
    char **avg;
    char *tokeen;
	int len = 0;

	_memset(tmp, 0, 256);
	len = _strlen(tokeen) + _strlen(avg[0]) + 2;
	_strcat(tmp, tokeen);
	_strcat(tmp, "/");
	_strcat(tmp, avg[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}}
