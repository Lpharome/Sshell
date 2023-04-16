#include "main.h"
/**
 * _puts - prints a string
 * @str: string to print
 */
void _puts(char *str)
{
	int c;

	for (c = 0; str[c] != '\0'; c++)
		_putchar(str[c]);
	_putchar('\n');
}
/**
 * _putchar - prints a character
 * @c: character to print
 *
 * Return: return value of write syscall
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _memset - fills memory with a constant byte
 * @s: character array to fill
 * @b: constant byte to fill with
 * @n: how many bytes to fill
 * Return: the pointer to the char array
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
