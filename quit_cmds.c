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
		EXIT_CODE_STATUS = atoi(argv[1]);
	printf("%d %s", EXIT_CODE_STATUS);
	kill(getpid(), SIGTERM);
}
