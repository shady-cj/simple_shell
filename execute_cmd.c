#include "main.h"
/**
 * This contain functions that helps in executing commands
 */


int execute(char *buffer, size_t i, char ***argv)
{
	int ret;

	buffer = strip(buffer, i);
	if (strlen(buffer) == 0)
	{
		return (2);
	}
	*argv = split(buffer);
	ret = parse_cmd(*argv);
	return (ret);
}


int execute_helper(char **argv)
{	
	int v_cmd, child_p, isdir;
	int (*func)(char **);
	int status = 0;

	func = map_cmd(argv[0]);
	if (func != NULL)
	{
		return (func(argv));
	}
	else
	{
		v_cmd = get_cmd_from_path(argv[0]);
		isdir = is_dir_check(argv[0]);
		if (v_cmd == 0)
		{
			fprintf(stderr, "./shell: %s: ", argv[0]);
			if (isdir)
				fprintf(stderr, "No such file or directory\n");
			else
				fprintf(stderr, "command not found\n");
			return (1);
		}
		child_p = fork();
		if (child_p == 0)
		{
			if (execvpe(argv[0], argv, environ) == -1)
			{
				perror("./shell");
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (status);
}
