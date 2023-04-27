#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs_alx(av[0]);
				_eputs_alx(": 0: Can't open ");
				_eputs_alx(av[1]);
				_eputchar_alx('\n');
				_eputchar_alx(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list_alx(info);
	read_history_alx(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
