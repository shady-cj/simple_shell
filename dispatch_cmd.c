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
	while (buffer[i])
	{
		if (buffer[i] == ';')
		{
			cmd[j] = '\0';
			*cmd_str = cmd;
			ex = execute(*cmd_str, j, argv);
			re_initializer(&cmd, &buf_size, interactive, 20, 0);
			if (ex != -2)
				free_args(*argv);
			ex = ex == -2 ? 0 : ex;
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
	if (ex != -2)
		free_args(*argv);
	ex = ex == -2 ? 0 : ex;
	return (ex);
}
/**
 * parse_cmd - This helper functions parses the commands to check for
 * logical OR and logical AND in the command statement
 * @argv: The arrays of commands to execute
 * Description: The ret variable is used to keep track of the previous return
 * value type variable is used to keep track of the previously encountered type
 * where 1 - Logical AND
 * 2 - Logical OR
 * 0 - None was encountered
 * lor variable to keep track of the logical OR In or order to know whether to
 * proceed with logical AND or not and same for Logical OR.
 * Return: The exit status
 */
int parse_cmd(char **argv)
{
	char *arr[100];
	size_t i = 0, j = 0;
	int ret = -1;
	int type = 0;
	int lor = 0;

	while (argv[i])
	{
		if (strcmp(argv[i], "&&")  == 0 && arr[0] != NULL)
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
		if (strcmp(argv[i], "||") == 0 && arr[0] != NULL)
		{
			if (ret == 0 && lor)
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
	if (arr[0] == NULL)
		return (0);
	if ((type == 1 && ret > 0) || (type == 2 && ret == 0))
		return (ret);

	if (strcmp(strip(arr[0], strlen(arr[0])), "&&\0") == 0
		|| strcmp(strip(arr[0], strlen(arr[0])), "||\0") == 0)
	{
		arr[0] = strip(arr[0], strlen(arr[0]));
		fprintf(stderr, "./shell: syntax error ");
		fprintf(stderr, "near unexpected token `%s'\n", arr[0]);
		re_init_arr(&arr[0]);
		return (1);
	}
	ret = execute_helper(arr);
	re_init_arr(&arr[0]);
	return (ret);
}
/**
 * re_init_arr - This function helps to re initialize an array with NULL
 * @opt: The array to re initialize
 * Return: void
 */
void re_init_arr(char **opt)
{
	while (*opt)
	{
		*opt = NULL;
		opt++;
	}
}
