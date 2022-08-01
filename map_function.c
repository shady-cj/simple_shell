#include "main.h"
/**
 * map_cmd - Maps the command to their functions
 * @argv: The arrays of commands to implement
 * Return: Pointer to the funtion to be implemented
 */
void (*map_cmd(char *str))(char **argv)
{
	size_t i = 0;

	cmd args[] = {
		{"cd", handle_cd},
		{NULL, NULL}
	};
	while (args[i].cmd_type)
	{
		if (strcmp(args[i].cmd_type, str) == 0)
		{
			return (args[i].func);
		}
		i++;
	}
	return (NULL);
}
