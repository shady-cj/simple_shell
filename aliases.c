
#include "main.h"

/**
 * handle_alias - The function to handle aliases like storing and
 * printing of aliases
 * @argv: The list of commands
 * Return: status code
 */
int handle_alias(char **argv)
{
	int ret;

	if (argv[1] == NULL)
		ret = print_aliases();
	else
		ret = store_aliases(argv);
	return (ret);
}

/**
 * store_aliases - It stores the new alias to the global alias linked
 * list
 * @argv: The list of args
 * Return: exit code
 */
int store_aliases(char **argv)
{
	char *name, *value;
	int i = 1, ret = 0, sf = 0, st;

	while (argv[i])
	{
		
		name = get_alias_name(argv[i], &sf);
		value = get_alias_value(argv[i]);
		if (name == NULL || value == NULL)
		{
			if (!sf)
				ret = 1;
			i++;
			sf = 0;
			continue;
		}
		st = add_alias_to_list(name, value);
		if (ret == 0)
			ret = st;
		i++;
	}
	return (ret);
}
/**
 * get_alias_name - This extract the alias name from the expression
 * e.g alias name=value
 * @str: The string to extract from.
 * @sf: is an address to know if an alias name was found
 * Return: pointer to the allocated string
 */
char *get_alias_name(char *str, int *sf)
{
	char *p = str;
	char *buf = malloc(sizeof(char) * 40);
	int i = 0, found = 0;

	if (buf == NULL)
		return (NULL);
	while (*p != '=' && *p != '\0')
	{
		if (*p == '\'' || *p == '\"')
		{
			p++;
			continue;
		}
		buf[i] = *p;
		p++;
		i++;
	}
	buf[i] = '\0';
	if (*p == '\0')
	{
		found = search_alias(buf);
		if (found)
		{
			free(buf);
			*sf = 1;
			return (NULL);
		}
		fprintf(stderr, "./shell: alias: ");
		fprintf(stderr, "%s: not found\n", buf);
		free(buf);
		return (NULL);
	}
	return (buf);
}

/**
 * get_alias_value - This extract the alias value from the expression
 * e.g alias name=value
 * @str: The string to extract from
 * Return: pointer to the allocated string
 */
char *get_alias_value(char *str)
{
	char *p = str;
	int i = 0;
	char *buf = malloc(sizeof(char) * 500);

	if (buf == NULL)
		return (NULL);
	while (*p != '=' && *p != '\0')
		p++;
	if (*p == '=')
	{
		p++;
		while (*p)
		{
			if (*p == '\'' || *p == '\"')
			{
				p++;
				continue;
			}
			buf[i] = *p;
			i++;
			p++;
		}
		buf[i] = '\0';
		return (buf);
	}
	free(buf);
	return (NULL);

}

/**
 * add_alias_to_list - creates a linked list for the alias and
 * replaces the value if alias already exist
 * @name: The name for the alias
 * @value: The value to the name
 * Return: 0 if sucessful and 1 if error
 */
int add_alias_to_list(char *name, char *value)
{	
	alias *ptr;
	alias *new;

	if (alias_list_head == NULL)
	{
		alias_list_head = malloc(sizeof(alias));
		if (alias_list_head == NULL)
			return (1);
		alias_list_head->name = name;
		alias_list_head->value = value;
		alias_list_head->link = NULL;
		return (0);
	}
	ptr = alias_list_head;
	while (ptr->link)
	{
		if (strcmp(ptr->name, name) == 0)
		{
			free(ptr->value);
			free(name);
			ptr->value = value;
			return (0);
		}
		ptr = ptr->link;
	}
	if (strcmp(ptr->name, name) == 0)
	{
		free(ptr->value);
		free(name);
		ptr->value = value;
		return (0);
	}
	new = malloc(sizeof(alias));
	if (new == NULL)
		return (1);
	new->name = name;
	new->value = value;
	new->link = NULL;
	ptr->link = new;
	new = NULL;
	return(0);
}
