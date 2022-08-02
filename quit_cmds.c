#include "main.h"
/**
 * The file Contains commands associated with quitting the shell
 */

/**
 * handle_exit - A simple helper function that exits the shell when exit
 * command is typed
 * @argv: The array of args
 * Return: void
 */

void handle_exit(char __attribute__((unused))**argv)
{
	if (argv[1])
		exit(atoi(argv[1]));
	exit(0);
}
