#include "main.h"
/**
 * main - This is the entry point
 * for now it's main functionality is to initiate the shell
 * Return: void
 */
int main(int argc, char **argv)
{
	int fd;
	if (argc > 1)
	{
		fd = access(argv[1], R_OK);
		if (fd == -1)
		{
			perror("./shell");
			return (errno);
		}
	}
	return (shell(argc, argv[1]));
}

