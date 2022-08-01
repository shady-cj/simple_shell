#include "main.h"
/**
 * This file contain helper function that works on directory level
 * operation
 */
/**
 * handle_cd - The function handles directory changing
 * @argv: Array of commands
 * Return: 0 of successful -1 if not
 */
void handle_cd(char **argv)
{
	int ret;

	ret = chdir(argv[1]);
	if (ret != 0)
	{
		printf("bash: %s: %s:", argv[0], argv[1]);
		printf("No such file or directory\n");
	}
}
