#include "main.h"


char *P_NAME = NULL;
size_t CODE_C = 0;
/**
 * main - This is the entry point
 * for now it's main functionality is to initiate the shell
 * @argc: The number of arguments passed into the command
 * no. 1 is always the name of the executable itself
 * @argv: The argument vector i.e the list ox argument
 * passed into this program
 * Return: status code of the program
 */
int main(int argc, char **argv)
{
	int fd;

	P_NAME = argv[0];
	if (argc > 1)
	{
		fd = access(argv[1], R_OK);
		if (fd == -1)
		{
			fprintf(stderr, "%s: %lu: ", P_NAME, CODE_C);
			fprintf(stderr, "Can't open %s\n", argv[1]);
			return (127);
		}
	}
	return (shell(argc, argv[1]));
}

