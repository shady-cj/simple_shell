#include "main.h"
/**
 * This file contains function that helps in allocating
 * and reallocating memory..
 */

/**
 * alloc_str - Helps to allocate memory to strings i.e arrays of
 * characters and also check for the memory availability
 * @size: The size to allocate for each characters
 * Return: A pointer to the allocated memory
 */
char *alloc_str(size_t size)
{
	char *str;

	str = malloc(sizeof(char) * size);
	if (str == NULL)
		exit(1);

	return (str);
}
/**
 * realloc_str - This function helps to reallocate memory to an already
 * allocated string pointer that ran out of memory this function also
 * make sure to free the existing memory in the event of failure of
 * memory reallocation
 * @buffer: A pointer to the existing string
 * @size: The new size to allocate
 * Return: A pointer to the newly allocated memory
 */

char *realloc_str(char *buffer, size_t size)
{
	char *new_buffer;

	new_buffer = realloc(buffer, size);
	if (new_buffer == NULL)
	{
		free(buffer);
		buffer = NULL;
		exit(1);
	}
	return (new_buffer);
}

/**
 * alloc_str_arr - The helper function also helps to allocate memory to string
 * but only to string associated with and array.. which later frees the rest of
 * the strings in the event of an error
 * @size: The size of the new string
 * @arr: The main array that contains the array of strings
 * @idx: The current index to allocate the string
 * @type: The type of allocation 0 for malloc 1 for realloc
 * Return: on Success returns a pointer to the newly reallocate memory location
 */
char *alloc_str_arr(size_t size, char **arr, size_t idx, int type)
{
	char *new_str;
	
	if (type == 0)
		new_str = malloc(sizeof(char) * size);
	else
		new_str = realloc(arr[idx], size);
	if (new_str == NULL)
	{
		while (idx != 0)
		{
			free(arr[idx]);
			idx--;
		}
		free(arr[idx]);
		free(arr);
		arr = NULL;
		exit(1);
	}
	return (new_str);
}

/**
 * free_args - Helps to free array of strings previously allocated
 * @args: The array of strings
 * Return: void
 */
void free_args(char **argv)
{
	int i = 0;

	while (argv[i])
	{
		free(argv[i]);
		i++;
	}

	free(argv);
	argv = NULL;
}
