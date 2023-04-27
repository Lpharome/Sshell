#include "shell.h"

/**
 * _myenv_alx - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv_alx(info_t *info)
{
	print_list_str_alx(info->env);
	return (0);
}

/**
 * _getenv_alx - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv_alx(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv_alx - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv_alx(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs_alx("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv_alx(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv_alx - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myunsetenv_alx(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs_alx("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv_alx(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list_alx - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list_alx(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
