
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
	char *s;
	char str[3000];

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
		if (*s == '#')
		{
			comment = 1;
			continue;
		}
		check_for_variable(s, str);
		argv[i] = strdup(str);
		free(s);
		s = NULL;
		i++;
	}
	return (argv);
}

void check_for_variable(char *cmd_str, char *str)
{
	char *var, *pl, *cmd;
	char sub[2000];
	int i = 0, j;

	cmd = cmd_str;
	while (*cmd)
	{
		if (*cmd == '$')
		{
			cmd++;
			if (*cmd == '$' || *cmd == '?')
			{
				if (*cmd == '$')
					_itoa(getpid(), sub);
				else
					_itoa(get_exit_code(), sub);
				pl = sub;
				while (*pl)
				{
					str[i] = *pl;
					pl++;
					i++;
				}
				cmd++;
				continue;
			}
			else if(*cmd != '\0')
			{
				j = 0;
				while (*cmd != '$' && *cmd != '\0')
				{
					sub[j] = *cmd;
					j++;
					cmd++;
				}
				sub[j] = '\0';
				var = get_env(sub);
				
				if (var != NULL)
				{
					pl = var;
					while (*pl)
					{
						str[i] = *pl;
						pl++;
						i++;
					}
					free(var);
				}
				continue;
			}
			else
				cmd--;
		}
		str[i] = *cmd;
		cmd++;
		i++;
	}
	str[i] = '\0';
}
