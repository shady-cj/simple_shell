#include "main.h"

/**
 * shell - This is the main function that implements the shell takes in
 * no arguments
 * Description: The shell function is the main function that connects other
 * functions it takes in the inputs and returns corresponding output as the
 * traditional shell would
 */

void shell(void)
{
	char *buffer;
	size_t buf_size = 40, i = 0;
	signed char c;
	char **argv;
	int child_p;
	void (*func)(char **);

	buffer = alloc_str(buf_size);
	printf("$ ");
	do {
		c = getc(stdin);
		if (c == '\n')
		{
			buffer = strip(buffer, i);
			if (strlen(buffer) == 0)
			{
				re_initializer(buffer, &buf_size, &i);
				continue;
			}
			argv = split(buffer);
			func = map_cmd(argv[0]);
			if (func != NULL)
			{
				func(argv);
			}
			else
			{
				child_p = fork();
				if (child_p == 0)
				{
					if (execvpe(argv[0], argv, environ) == -1)
					{
						perror("Error");
						exit(1);
					}
				}
				else
				{
					wait(NULL);
				}
			}
			re_initializer(buffer, &buf_size, &i);
			continue;
		}
		if (c == EOF)
		{
			printf("\n");
			continue;
		}
		if (i == buf_size)
		{
			buf_size += 40;
			buffer = realloc_str(buffer, buf_size);
		}
		buffer[i] = c;
		i++;
	} while (feof(stdin) == 0);
}

/**
 * re_initializer - This function helps to avoid repetition while
 * reinitializing my variables after a process ends or a shell
 * command executes
 * @buffer: The existing string
 * @buf_sizs: A pointer to the buf_size initialize back to 40
 * @i: A pointer to the interator re_initialize to 0
 * Return: void
 */
void re_initializer(char *buffer, size_t *buf_size, size_t *i)
{
	free(buffer);
	*buf_size = 40;
	*i = 0;
	buffer = alloc_str(*buf_size);
	printf("$ ");
}
