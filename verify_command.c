#include "main.h"
/**
 * get_cmd_from_path - Gets the command and check if it is in the present path.
 * @cmd: The command typed.
 * Return: int
 * Description: This function gets a command as an argument e.g
 * ls, cat etc and checks
 * if the command is present in the paths directories... e.g
 * /bin/ls /usr/local/bin/ls.
 */
int get_cmd_from_path(char *cmd)
{
	char *s;
	char **dirs;
	int i = 0;
	path_dir *head = NULL;

	s = get_env("PATH");
	if (s != NULL)
	{
		dirs = split_path(s);
		while (dirs[i])
		{
			add_path(&head, dirs[i]);
			i++;
		}
		free_args(dirs);
	}
	return (check_path(head, cmd));
}
/**
 * split_path - An helper function to help split the path dirs at every ":"
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
	argv[i] = alloc_str_arr(buf_size_j, argv, i, 0);
	while (*s_ptr)
	{
		if (*s_ptr != ':')
		{
			if (j == buf_size_j)
			{
				buf_size_j += 40;
				argv[i] =  alloc_str_arr(buf_size_j, argv, i, 1);
			}
			argv[i][j] = *s_ptr;
			j++;
		}
		else
		{
			argv[i][j] = '\0';
			i++;
			buf_size_j = 40;
			argv[i] = alloc_str_arr(buf_size_j, argv, i, 0);
			j = 0;
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
 * add_path - This function creates a linked list of the directories
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
 * check_path - Checks every directory in the path from the linked list
 * and using stats to see if the command file is present
 * @head: The head node
 * @cmd: The command to check
 * Return: int 1 if found 0 if not found
 */
int check_path(path_dir *head, char *cmd)
{
	struct stat st;
	char s[1024];
	path_dir *ptr;

	if (head == NULL)
	{
		if (stat(cmd, &st) == 0)
			return (1);
		return (0);
	}
	ptr = head;
	while (ptr)
	{
		memcpy(s, ptr->dir, strlen(ptr->dir) + 1);
		strcat(s, "/\0");
		strcat(s, cmd);
		if (stat(cmd, &st) == 0 || stat(s, &st) == 0)
		{
			free_linked_path(head);
			return (1);
		}
		ptr = ptr->link;
	}
	free_linked_path(head);
	return (0);
}

/**
 * free_linked_path - Helps to free the path linked list from memory
 * @head: The head pointer of the linked list
 * Return: void
 */
void free_linked_path(path_dir *head)
{
	path_dir *ptr, *pl;

	if (head == NULL)
		return;
	ptr = head;

	while (ptr)
	{
		free(ptr->dir);
		ptr->dir = NULL;
		pl = ptr->link;
		free(ptr);
		ptr = pl;
	}
	head = NULL;
}
