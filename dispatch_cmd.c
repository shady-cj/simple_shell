#include "main.h"

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
