#include "main.h"
/**
 * map_cmd - Maps the command to their functions
 * @str: The command to map
 * Return: Pointer to the funtion to be implemented
 */
int (*map_cmd(char *str))(char **argv)
{
	size_t i = 0;

	cmd args[] = {
		{"cd", handle_cd},
		{"exit", handle_exit},
		{"setenv", handle_setenv},
		{"unsetenv", handle_unsetenv},
		{"alias", handle_alias},
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
