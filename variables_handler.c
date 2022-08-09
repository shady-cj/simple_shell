
#include "main.h"
/**
 * variable_substitution - The functions takes in arrays of commands and check for
 * where variables are invoked or commnents are made and then substitute them
 * @argv: The array of commands
 * Return: The updated list of commands
 */
char **variable_substitution(char **argv)
{
	int comment = 0, i = 0;
	char *s, *var, *pl;
	char str[20];

	while (argv[i])
	{
		if (comment)
		{
			free(argv[i]);
			argv[i] = NULL;
			i++;
			continue;
		}
		s = argv[i];
		if (*s == '$')
		{
			pl = argv[i];
			s++;
			if (*s == '$')
			{
				_itoa(getpid(), str);
				argv[i] = strdup(str);
			}
			else if (*s == '?')
			{
				_itoa(get_exit_code(), str);
				argv[i] = strdup(str);
			}
			else
			{
				var = get_env(s);
				argv[i] = var ? var : strdup(" \0");
			}
			free(pl);
		}
		else if (*s == '#')
		{
			comment = 1;
			continue;
		}
		i++;
	}
	return (argv);
}
