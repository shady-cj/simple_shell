#include "main.h"
/**
 * handle_cd - The function handles directory changing
 * @argv: Array of commands
 * Return: 0 of successful -1 if not
 */
int handle_cd(char **argv)
{
	int ret;
	char cwd[1024];
	char oldcwd[1024], *s;

	if (getcwd(oldcwd, sizeof(oldcwd)) == NULL)
		perror("error");
	if (argv[1] == NULL)
		ret = chdir(getenv("HOME") ? getenv("HOME") : ".\0");
	else if (strcmp(argv[1], "-\0") == 0)
	{
		s = getenv("OLDPWD") ? getenv("OLDPWD") : getenv("PWD");
		printf("%s\n", s);
		ret = chdir(s);
	}
	else
		ret = chdir(argv[1]);
	if (ret != 0)
	{
		printf("./shell: %s: %s: ", argv[0], argv[1]);
		printf("No such file or directory\n");
		return (1);
	}
	else
	{
		setenv("OLDPWD", oldcwd, 1);
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("error");
			return (1);
		}
		else
		{
			setenv("PWD", cwd, 1);
		}
	}
	return (0);
}

/**
 * is_dir_check - This checks if the command contains a directory
 * @str: The string to check through
 * Return: 1 if found and 0 if none
 */
int is_dir_check(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
