#include "main.h"
/**
 * prompt - writes a prompt
 *
 * Return: 0 on sucess
 */
int prompt(void)
{
	char *prompt = "$ ";
	ssize_t putcount = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		putcount = write(STDOUT_FILENO, prompt, 2);
		if (putcount == -1)
			exit(0);
	}
	return (0);
}
/**
 * _read - reads stdin and stores it in a pipe
 *
 * Return: a pointer to the pipe
 */
char *_read(void)
{
	ssize_t getcount = 0;
	size_t n = 0;
	char *pipe = NULL;
	int j = 0;

	getcount = getline(&pipe, &n, stdin);
	if (getcount == -1)
	{
		free(pipe);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (pipe[getcount - 1] == '\n' || pipe[getcount - 1] == '\t')
		pipe[getcount - 1] = '\0';
	for (j = 0; pipe[j]; j++)
	{
		if (pipe[j] == '#' && pipe[j - 1] == ' ')
		{
			pipe[j] = '\0';
			break;
		}
	}
	return (pipe);
}
/**
 * _fullpathpipe - finds the string to call execve on
 * @avg: pointer to array of user strings
 * @PATH: pointer to PATH string
 * @copy: pointer to copy of PATH string
 *
 * Return: a pointer to string to call execve on
 */
char *_fullpathpipe(char **avg, char *PATH, char *copy)
{
	char *tokeen = NULL, *fullpathpipe = NULL, *concatstr = NULL;
	static char tmp[256];
	int PATHcount = 0, fullpathmap = 0, z = 0, toklen = 0;
	struct stat h;

	copy = NULL;
	copy = _strdup(PATH);
	PATHcount = _splitPATH(copy);
	tokeen = strtok(copy, ": =");
	while (tokeen != NULL)
	{
		concatstr = _concat(tmp, avg, tokeen);
		if (stat(concatstr, &h) == 0)
		{
			fullpathpipe = concatstr;
			fullpathmap = 1;
			break;
		}
		if (z < PATHcount - 2)
		{
			toklen = _strlen(tokeen);
			if (tokeen[toklen + 1] == ':')
			{
				if (stat(avg[0], &h) == 0)
				{
					fullpathpipe = avg[0];
					fullpathmap = 1;
					break;
				}
			}
		}
		z++;
		tokeen = strtok(NULL, ":");
	}
	if (fullpathmap == 0)
		fullpathpipe = avg[0];
	free(copy);
	return (fullpathpipe);
}
/**
 * checkbuiltins - check if first user string is a built-in
 * @avg: pointer to array of user of strings
 * @pipe: pointer to user string
 * @exitstatus: exit status of execve
 * Return: 1 if user string is equal to env or 0 otherwise
 */
int checkbuiltins(char **avg, char *pipe, int exitstatus)
{
	int i;

	if (_strcmp(avg[0], "env") == 0)
	{
		_env();
		for (i = 0; avg[i]; i++)
			free(avg[i]);
		free(avg);
		free(pipe);
		return (1);
	}
	else if (_strcmp(avg[0], "exit") == 0)
	{
		for (i = 0; avg[i]; i++)
			free(avg[i]);
		free(avg);
		free(pipe);
		exit(exitstatus);
	}
	else
		return (0);
}
/**
 * _forkprocess - create child process to execute based on user input
 * @avg: pointer to array of user of strings
 * @pipe: pointer to user string
 * @fullpathpipe: pointer to user input
 *
 * Return: 0 on success
 */
int _forkprocess(char **avg, char *pipe, char *fullpathpipe)
{
	int i, status, result, exitstatus = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		result =  execve(fullpathpipe, avg, environ);
		if (result == -1)
		{
			perror(avg[0]);
			for (i = 0; avg[i]; i++)
				free(avg[i]);
			free(avg);
			free(pipe);
			exit(127);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
	}
	for (i = 0; avg[i]; i++)
		free(avg[i]);
	free(avg);
	free(pipe);
	return (exitstatus);
}
