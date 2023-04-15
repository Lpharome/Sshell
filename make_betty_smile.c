#include <stdio.h>
/**
* main - print the number arguments
* @argc:number number arguments
* @argv: array of arguments
*
* Return: number of arguments
*/
int main(int argc, char *argv[])
{
	if (argv[0])
	{
		int length = argc - 1;

		printf("%d", length);
		printf("\n");
	}
	return (0);
}
