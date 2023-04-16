#include "main.h"
/**
 * tokenize - creates array of tokens based on user string
 * @buffer: pointer to user string
 *
 * Return: pointer to array of user strings
 */
char **tokenize(char *pipe)
{
	char *token = NULL;
	int i = 0, alphacount = 0;
	char *nanometer = " \n";
	char **avg = NULL;

	alphacount = _splitstring(pipe);
	if (!alphacount)
		return (NULL);
	avg = malloc((alphacount + 1) * sizeof(char *));
	if (avg == NULL)
		exit(1);
	token = strtok(pipe, nanometer);
	while (token != NULL)
	{
		avg[i] = _strdup(token);
		token = strtok(NULL, nanometer);
		i++;
	}
	avg[i] = NULL;
	return (av);
}}