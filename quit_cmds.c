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

int handle_exit(char __attribute__((unused))**argv)
{
	handle_EXIT(argv[1] ? atoi(argv[1]) : 0);
	return (0);
}
