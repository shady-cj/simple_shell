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
			printf("alias %s='%s'\n", ptr->name, ptr->value);
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
		printf("alias %s='%s'\n", ptr->name, ptr->value); 
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

	if (ptr)
	{
		pl = ptr->link;
		free(ptr->name);
		free(ptr->value);
		free(ptr);
		ptr = pl;
	}
	alias_list_head = NULL;
}
