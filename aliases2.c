#include "main.h"


/**
 * search_alias - searches for an alias by name
 * @name: The name to search
 * Return: 1 if found and 0 if not;
 */

int search_alias(char *name)
{
	alias *ptr;

	if (alias_list_head == NULL)
		return (0);
	ptr = alias_list_head;

	while (ptr)
	{
		if (strcmp(ptr->name, name) == 0)
		{
			printf("%s='%s'\n", ptr->name, ptr->value);
			return (1);
		}
		ptr = ptr->link;
	}
	return (0);
}


/**
 * print_aliases - Prints the aliases and their value
 * Return: status code
 */
int print_aliases(void)
{
	alias *ptr;

	if (alias_list_head == NULL)
		return (0);
	
	ptr = alias_list_head;
	while (ptr)
	{
		printf("%s='%s'\n", ptr->name, ptr->value); 
		ptr = ptr->link;
	}
	return (0);
}

/**
 * free_aliases - Free alias on termination
 * Return: void
 */
void free_aliases(void)
{
	alias *ptr;
	alias *pl;

	if (alias_list_head == NULL)
		return;
	ptr = alias_list_head;

	while (ptr)
	{
		pl = ptr->link;
		free(ptr->name);
		free(ptr->value);
		free(ptr);
		ptr = pl;
	}
	alias_list_head = NULL;
}
/**
 * get_alias - Gets the value of an alias
 * @str: The alias name
 * Return: The value of the alias
 */
char *get_alias(char *str)
{
	alias *ptr;

	if (alias_list_head == NULL)
		return (NULL);
	ptr = alias_list_head;

	while (ptr)
	{
		if (strcmp(ptr->name, str) == 0)
			return (ptr->value);

		ptr = ptr->link;
	}
	return (NULL);
}
/**
 * sub_alias -Substitute aliases in commands
 * @buffer: The string of commands
 * Return: The new string.
 */
char *sub_alias(char *buffer)
{
	int j = 0, i = 0;
	size_t size = 80, k = 0;
	char str[40];
	char *new, *ptr;

	if (strlen(buffer) == 0)
		return (buffer);
	buffer = check_space(buffer);
	while (buffer[i] != ' ' && buffer[i] != '\0')
	{
		str[j] = buffer[i];
		j++;
		i++;
	}
	str[j] = '\0';
	ptr = get_alias(str);
	if (ptr == NULL)
		return (buffer);
	new =  alloc_str(size);
	while (*ptr)
	{
		new[k] = *ptr;
		ptr++;
		k++;
	}
	while (buffer[i])
	{
		if (k == size)
		{
			size += 40;
			new = realloc_str(new, size);
		}
		new[k] = buffer[i];
		i++;
		k++;
	}
	new[k] = '\0';
	free(buffer);
	return (new);
}
