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
	kill(getpid(), SIGTERM);
	return (0);
}
