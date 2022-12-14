#include "main.h"


/**
 * execute - This function executes the commands with the aid of
 * variable substition which substitute variables and parse_cmd
 * that parses the command to check for commnents logical AND
 * and logical OR
 * @buffer: The main buffer containing the string of commands
 * @i: The length of the buffer
 * @argv: The arrays to split the commands into before passing
 * to exec
 * Return: The status code of the operation
 */

int execute(char *buffer, size_t i, char ***argv)
{
	int ret;

	buffer = strip(buffer, i);
	if (strlen(buffer) == 0)
	{
		return (-2);
	}
	*argv = split(buffer);
	*argv = variable_substitution(*argv);
	ret = parse_cmd(*argv);
	return (ret);
}

/**
 * execute_helper - Carries out the execution by first checking if the
 * command exists then passing it to exec to execute
 * @argv: The array of commands to execute
 * Return: The exit code of the operation.
 */
int execute_helper(char **argv)
{
	int v_cmd, child_p, status = 0;
	int (*func)(char **);

	if (argv[0] == NULL)
		return (1);
	func = map_cmd(argv[0]);
	if (func != NULL)
	{
		return (func(argv));
	}
	else
	{
		v_cmd = get_cmd_from_path(argv[0]);	
		if (v_cmd == 0)
		{
			fprintf(stderr, "%s: %lu: %s: ", P_NAME, CODE_C, argv[0]);
			fprintf(stderr, "not found\n");
			return (127);
		}
		child_p = fork();
		if (child_p == 0)
		{
			if (execvpe(argv[0], argv, environ) == -1)
				perror("./shell");
		}
		wait(&status);
	}
	if (WIFEXITED(status))
		status =  WEXITSTATUS(status);
	else
		status = 1;
	return (status);
}

/**
 * is_dir_check - Checks if command is an absolute or relative path as in
 * /../ or .././
 * @str: The command to check
 * Return: 1 if found 0 if not
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
