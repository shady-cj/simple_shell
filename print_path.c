#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *get_env(char *s);
char **get_key_value(char *s);
/**
 * main - Prints the directories of PATH environment variable
 * @argc: The arg count
 * @argv: The arg vector
 * @env: The environment variables
 * Return: int
 */
int main(int __attribute__((unused)) argc,
	char** __attribute__((unused)) argv,
	char **env
	)
{
	char *s_dup;
	char *s;

	s_dup = get_env("PATH", env);
	s = s_dup;

	while (*s)
	{
		if (*s == ':')
			putchar('\n');
		else
			putchar(*s);
		s++;
	}
	free(s_dup);
	putchar('\n');
}
/**
 * get_env - The get_env function gets the environment variable
 * value
 * @s: The environment variable to fetch
 * @env: The list of environment variables
 * Return: The value of the env
 */
char *get_env(char *s, char **env)
{
	int i = 0;
	char **argv;
	char *str;

	while (env[i])
	{
		argv = get_key_value(env[i]);
		if (strcmp(argv[0], s) == 0)
		{
			str = strdup(argv[1]);
			free(argv[0]);
			free(argv[1]);
			free(argv[2]);
			free(argv);
			argv = NULL;
			return (str);
		}
		i++;
		free(argv[0]);
		free(argv[1]);
		free(argv[2]);
		free(argv);
		argv = NULL;
	}
	return ("No environment variable of such");
}
/**
 * get_key_value - This helper function helps to filter out the
 * environment key and value
 * @s: The string containing the key and value of the env variable
 * Return: A key value pair of the env and it's value
 */
char **get_key_value(char *s)
{
	size_t key_size = 40, value_size = 1024;
	char *key = malloc(sizeof(char) * key_size);
	char *value = malloc(sizeof(char) * value_size);
	int i = 0, j = 0;
	char **argv = malloc(sizeof(char *) * 3);

	if (argv == NULL || key == NULL || value == NULL)
		exit(1);
	while (s[i] != '=')
	{
		if (i == key_size)
		{
			key_size += 40;
			key = realloc(key, key_size);
			if (key == NULL)
			{
				free(key);
				free(argv);
				exit(1);
			}
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
			value = realloc(value, value_size);
			if (value == NULL)
			{
				free(value);
				free(key);
				free(argv);
				exit(1);
			}
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
