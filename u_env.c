#include "main.h"
/**
 * _env - prints the environment
 *
 * Return: 0 on success
 */
int _env(void)
{
	int i;

	for (i = 0; envi[i]; i++)
		_puts(envi[i]);
	return (0);
}
