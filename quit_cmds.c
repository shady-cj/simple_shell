#include "main.h"
int check_alpha(char *);
/**
 * handle_exit - A simple helper function that exits the shell when exit
 * command is typed
 * @argv: The array of args
 * Return: void
 */

int handle_exit(char __attribute__((unused))**argv)
{
	if (argv[1] != NULL)
	{
		if (check_alpha(argv[1]))
		{
			fprintf(stderr, "./shell: 1: exit: ");
			fprintf(stderr, "Illegal number: %s\n", argv[1]);
			return (2);
		}
		if (atoi(argv[1]) < 0)
		{
			fprintf(stderr, "./shell: 1: exit: ");
			fprintf(stderr, "Illegal number: %s\n", argv[1]);
			return (2);
		}
	}
	handle_EXIT(argv[1] ? atoi(argv[1]) : 0);
	return (0);
}
/**
 * check_alpha - This function checks a string and check if alphabet are
 * present
 * @str: The string
 * Return: 1 if found 0 if not
 */
int check_alpha(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] > 57 || str[i] < 48)
			return (1);
		i++;
	}
	return (0);
}
