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
		return (0);
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

/**
 * print_env - Prints out the environment variable of the current shell
 * @argv: The list of commands
 * Return: status code
 */

int print_env(char __attribute__((unused)) **argv)
{
	int i = 0;

	if (environ == NULL)
		return (0);
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
