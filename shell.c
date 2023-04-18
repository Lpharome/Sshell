#include "main.h"
/**
 * main - runs the shell program
 *
 * Return: 0 on success
 */
int main(void)
{
	char *fullpathpipe = NULL, *copy = NULL, *pipe = NULL;
	char *PATH = NULL;
	char **avg = NULL;
	int exitstatus = 0;

	signal(SIGINT, SIG_IGN);
	PATH = _getenv("PATH");
	if (PATH == NULL)
		return (-1);
	while (1)
	{
		avg = NULL;
		prompt();
		pipe = _read();
		if (*pipe != '\0')
		{
			avg = tokenize(pipe);
			if (avg == NULL)
			{
				free(pipe);
				continue;
			}
			fullpathpipe = _fullpathpipe(avg, PATH, copy);
			if (checkbuiltins(avg, pipe, exitstatus) != 0)
				continue;
			exitstatus = _forkprocess(avg, pipe, fullpathpipe);
		}
		else
			free(pipe);
	}
	return (0);
}
