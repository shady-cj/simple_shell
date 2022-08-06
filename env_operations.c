#include "main.h"
/**
 *
 * This files contain the function to help set environment variables
 *
 */

/**
 * handle_setenv - An helper function that handles setting of environment
 * variables
 * @argv: The array of commands
 * Return: void
 */

void handle_setenv(char **argv)
{
	if (argv[1] == NULL || argv[2] == NULL)
		fprintf(stderr, "Err:");
	if (setenv(argv[1], argv[2], 1) != 0)
	{
		perror("Error");
	}
}

/**
 * handle_unsetenv - Unsets the environment variabe
 * @argv: The array of commands
 * Return: void
 */

void handle_unsetenv(char **argv)
{
	if (argv[1] == NULL)
		fprintf(stderr, "Err: ");
	if (unsetenv(argv[1]) != 0)
	{
		perror("Error");
	}
}
