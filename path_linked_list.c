#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct path {
	char *dir;
	struct path *link;
} path_dir;
path_dir *add_path(path_dir **head, char *str);
char *get_env(char *s, char **env);
char **get_key_value(char *s);
char **split_path(char *s);
void print_path(path_dir *);
/**
 * main - Prints the directories of PATH environment variable
 * @argc: The arg count
 * @argv: The arg vector
 * @env: The environment variables
 * Return: int
 */
int main(int __attribute__((unused)) argc,
	char __attribute__((unused)) **argv,
	char **env
	)
{
	char *s;
	char **dirs;
	int i = 0;

	path_dir *head = NULL;

	s = get_env("PATH", env);
	dirs = split_path(s);
	while (dirs[i])
	{
		add_path(&head, dirs[i]);
		i++;
	}
	print_path(head);
	return (0);
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
	size_t key_size = 40, value_size = 1024, i = 0, j = 0;
	char *key = malloc(sizeof(char) * key_size);
	char *value = malloc(sizeof(char) * value_size);
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
/**
 * split_path - An helper function to help the path dirs
 * @s: The string of directories
 * Return: an array of directories
 */
char **split_path(char *s)
{
	char **argv = NULL;
	char *s_ptr = s;
	ssize_t i = 0, j = 0, buf_size_i = 40, buf_size_j = 40;
	
	argv = malloc(sizeof(char *) * buf_size_i);
	if (argv == NULL)
		exit(1);
	argv[i] = malloc(sizeof(char) * buf_size_j);
	if (argv[i] == NULL)
	{
		free(argv);
		exit(1);
	}
	while (*s_ptr)
	{
		if (*s_ptr != ':')
		{
			if (j == buf_size_j)
			{
				buf_size_j += 40;
				argv[i] = realloc(argv[i], buf_size_j);
				if (argv[i] == NULL)
				{
					while (i >= 0)
					{
						free(argv[i]);
						i--;
					}
					free(argv);
					argv = NULL;
					exit(1);
				}
				

			}
			argv[i][j] = *s_ptr;
			j++;
		}
		else
		{
			argv[i][j] = '\0';
			i++;
			buf_size_j = 40;
			argv[i] = malloc(sizeof(char) * buf_size_j);
			j = 0;
			if (argv[i] == NULL)
			{
				while (i >= 0)
				{
					free(argv[i]);
					i--;
				}
				free(argv);
				argv = NULL;
				exit(1);
			}
		}
		s_ptr++;
	}
	argv[i][j] = '\0';
	argv[++i] = NULL;
	free(s);
	s = NULL;
	return (argv);
}

/**
 * add_path - This function creates a linked of the directories
 * in the path env variable
 * @head: The pointer to the head node
 * @str: The directory to store
 * Return: The head node
 */
path_dir *add_path(path_dir **head, char *str)
{
	path_dir *ptr = NULL;
	path_dir *new = NULL;
	ptr = *head;
	if (*head == NULL)
	{
		ptr = malloc(sizeof(path_dir));
		if (ptr == NULL)
			return (NULL);
		ptr->dir = strdup(str);
		ptr->link = NULL;
		*head = ptr;
	}
	else
	{
		new = malloc(sizeof(path_dir));
		if (new == NULL)
			return (NULL);
		while (ptr->link)
		{
			ptr = ptr->link;
		}
		new->dir = strdup(str);
		new->link = NULL;

		ptr->link = new;
	}
	return (*head);
}

/**
 * print_path - This print the path from the linked list
 * @head: The head node
 * Return: void
 */
void print_path(path_dir *head)
{
	path_dir *ptr;
	
	if (head == NULL)
		return;
	ptr = head;
	while (ptr)
	{
		printf("%s\n", ptr->dir);
		ptr = ptr->link;
	}
}
