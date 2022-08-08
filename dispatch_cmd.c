#include "main.h"

/**
 * dispatch - This dispatches commands and put into consideration
 * multiple commands
 * @buffer: The string that contains the series of command
 * @cmd_str: The present command that is the current executing command
 * which changes based on the next command from buffer
 * @argv: The pointer to the array of current commmand from @cmd_str
 * @interactive: The flag to know if it's in interactive mode or not
 * Return: The exit codes
 */

int dispatch(char *buffer, char **cmd_str, char ***argv, int interactive)
{
	size_t i = 0, j = 0, buf_size = 20;
	int ex;
	char *cmd;

	if (buffer == NULL)
		return (1);
	cmd = alloc_str(buf_size);
	while(buffer[i])
	{
		if (buffer[i] == ';')
		{
			cmd[j] = '\0';
			*cmd_str = cmd;
			ex = execute(*cmd_str, j, argv);
			re_initializer(&cmd, &buf_size, interactive, 20, 0);
			if (ex != 2)
				free_args(*argv);
			cmd = alloc_str(buf_size);
			j = 0;
			i++;
			continue;
		}
		if (j == buf_size)
		{
			buf_size *= 2;
			cmd = realloc(cmd, buf_size);
		}
		cmd[j] = buffer[i];
		i++;
		j++;
	}
	cmd[j] = '\0';
	*cmd_str = cmd;
	ex = execute(*cmd_str, j, argv);
	free_buffer(cmd_str);
	if (ex != 2)
		free_args(*argv);
	return (ex);
}

int parse_cmd(char **argv)
{
	char *arr[100];
	size_t i = 0, j = 0;
	int ret = -1;
	int type = 0;
	int lor = 0;

	while (argv[i])
	{
		if (strcmp(argv[i], "&&")  == 0)
		{
			if (ret > 0)
				return (ret);
			arr[j] = NULL;
			if (!lor)
				ret = execute_helper(arr);
			j = 0;
			i++;
			re_init_arr(&arr[0]);
			type = 1;
			lor = 0;
			continue;
		}
		if (strcmp(argv[i], "||") == 0)
		{
			if (ret == 0)
				return (ret);
			arr[j] = NULL;
			ret = execute_helper(arr);
			j = 0;
			i++;
			re_init_arr(&arr[0]);
			type = 2;
			lor = 1;
			continue;
		}
		arr[j] = argv[i];
		i++;
		j++;
	}
	arr[j] = NULL;
	if ((type == 1 && ret > 0) || (type == 2 && ret == 0))
		return (ret);
	ret = execute_helper(arr);
	return (ret);
}

void re_init_arr(char **opt)
{	
	while(*opt)
	{
		*opt = NULL;
		opt++;
	}
}
