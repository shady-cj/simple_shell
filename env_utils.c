

#include "main.h"
char *increase_value_size(char *value, char **argv, size_t size);
char *increase_key_size(char *key, char **argv, size_t size);
void free_argv(char **argv);
/**
 * get_env - The get_env function gets the environment variable
 * value
 * @s: The environment variable to fetch
 * Return: The value of the env
 */
char *get_env(char *s)
{
	int i = 0;
	char **argv;
	char *str;

	while (environ[i])
	{
		argv = get_key_value(environ[i]);
		if (argv == NULL)
			return (NULL);
		if (strcmp(argv[0], s) == 0)
		{
			str = strdup(argv[1]);
			free_argv(argv);
			return (str);
		}
		free_argv(argv);	
		i++;
	}
	return (NULL);
}

/**
 * get_key_value - This helper function helps to filter out the
 * environment key and value
 * @s: The string containing the key and value of the env variable
 * Return: A key value pair of the env and it's value
 */
char **get_key_value(char *s)
{
	size_t key_size = 40, value_size = 1024, i = 0, j = 0;
	char *key = malloc(sizeof(char) * key_size);
	char *value = malloc(sizeof(char) * value_size);
	char **argv = malloc(sizeof(char *) * 3);

	if (argv == NULL || key == NULL || value == NULL)
		return (NULL);
	while (s[i] != '=')
	{
		if (i == key_size)
		{
			key_size += 40;
			key = increase_key_size(key, argv, key_size);	
		}
		key[i] = s[i];
		i++;
	}
	key[i] = '\0';
	argv[0] = key;
	i++;
	while (s[i])
	{
		if (j == value_size)
		{
			value_size += 1024;
			
		}
		value[j] = s[i];
		j++;
		i++;
	}
	value[j] = '\0';
	argv[1] = value;
	argv[2] = NULL;
	return (argv);
}

/**
 * increase_key_size - Is an helper function to help reallocate the environment
 * key when it runs out of space..
 * @key: The previously allocated key
 * @argv: The main array of key value pairs...
 * @size: The new size to reallocate
 * Return: pointer to the newly allocated string
 */
char *increase_key_size(char *key, char **argv, size_t size)
{
	key = realloc(key, size);
	if (key == NULL)
	{
		free(key);
		key = NULL;
		free(argv);
		argv = NULL;
		exit(1);
	}
	return (key);

}


/**
 * increase_value_size - An helper function for the above get_key_value function to
 * reallocate the env variable value to the initial value when it runs out of space
 * @value: Pointer to the previously allocate value location
 * @argv: The argument vector containing the key value pair.
 * @size: The new size to reallocate
 * Return: The pointer to the newly allocated space
 */
char *increase_value_size(char *value, char **argv, size_t size)
{
	value = realloc(value, size);
	if (value == NULL)
	{
		free(value);
		value = NULL;
		free(argv[0]);
		free(argv);
		argv = NULL;
		exit(1);
	}
	return (value);
}

/**
 * free_argv - Helps to abstract the repetition of freeing the argument vectors
 * It frees the argument vectors after use..
 * @argv: The argument vector
 * Return: void
 */
void free_argv(char **argv)
{
	
	free(argv[0]);
	free(argv[1]);
	free(argv[2]);
	free(argv);
	argv = NULL;
}
