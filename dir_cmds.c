#include "main.h"
/**
 * This file contain helper function that works on directory level
 * operation
 */
/**
 * handle_cd - The function handles directory changing
 * @argv: Array of commands
 * Return: 0 of successful -1 if not
 */
int handle_cd(char **argv)
{
	int ret;
	char cwd[1024];
	char oldcwd[1024];

	if (getcwd(oldcwd, sizeof(oldcwd)) == NULL)
		perror("error");
	if (argv[1] == NULL)
		ret = chdir(getenv("HOME"));
	else if (strcmp(argv[1], "-\0") == 0)
	{
		printf("%s\n", getenv("OLDPWD"));
		ret = chdir(getenv("OLDPWD"));
	}
	else
		ret = chdir(argv[1]);
	if (ret != 0)
	{
		printf("bash: %s: %s: ", argv[0], argv[1]);
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
			setenv("PWD", cwd, 1);
	}
	printf("error %d\n", errno);
	return (0);
}
