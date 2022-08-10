#include "main.h"
/**
 * handle_setenv - An helper function that handles setting of environment
 * variables
 * @argv: The array of commands
 * Return: void
 */

int handle_setenv(char **argv)
{
	if (argv[1] == NULL || argv[2] == NULL)
		fprintf(stderr, "Err:");
	if (setenv(argv[1], argv[2], 1) != 0)
	{
		perror("Error");
		return (1);
	}
	return (0);
}

/**
 * handle_unsetenv - Unsets the environment variabe
 * @argv: The array of commands
 * Return: void
 */

int handle_unsetenv(char **argv)
{
	if (argv[1] == NULL)
		fprintf(stderr, "Err: ");
	if (unsetenv(argv[1]) != 0)
	{
		perror("Error");
		return (1);
	}
	return (0);
}
