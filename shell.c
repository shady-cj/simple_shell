#include "main.h"

char *buffer;
char **argv;
int exit_code;
void handle_z(int sig);

/**
 * shell - This is the main function that implements the shell takes in
 * no arguments
 * Description: The shell function is the main function that connects other
 * functions it takes in the inputs and returns corresponding output as the
 * traditional shell would
 */

void shell(void)
{
	size_t buf_size = 40, i = 0;
	signed char c;
	int child_p, interactive = isatty(STDIN_FILENO);
	void (*func)(char **);

	signal(SIGTSTP, &handle_z);
	signal(SIGINT, &handle_SIGINT);
	signal(SIGTERM, &handle_SIGTERM);
	buffer = alloc_str(buf_size);
	if (interactive)
		printf("$ ");
	do {
		c = getc(stdin);
		if (c == '\n')
		{
			buffer = strip(buffer, i);
			if (strlen(buffer) == 0)
			{
				re_initializer(&buf_size, &i, interactive);
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
						perror("./shell");
						free_args(argv);
						free_buffer();
						exit(0);
					}
				}
				else
				{
					wait(NULL);
				}
			}
			re_initializer(&buf_size, &i, interactive);
			free_args(argv);
			continue;
		}
		if (c == EOF)
		{
			if (interactive)
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

	printf("called");
	free_buffer();
	printf("called");
}

/**
 * re_initializer - This function helps to avoid repetition while
 * reinitializing my variables after a process ends or a shell
 * command executes
 * @buffer: The existing string
 * @buf_sizs: A pointer to the buf_size initialize back to 40
 * @i: A pointer to the interator re_initialize to 0
 * @sh: To check if it's called in interactive mode or not
 * Return: void
 */
void re_initializer(size_t *buf_size, size_t *i, int sh)
{
	free_buffer();
	*buf_size = 40;
	*i = 0;
	buffer = alloc_str(*buf_size);
	if (sh)
		printf("$ ");
}

void handle_z(int __attribute__((unused))sig)
{
	printf("\n$ ");
	fflush(stdout);
	return;
}
void handle_SIGINT(int __attribute__((unused))sig)
{
	free_buffer();
	printf("\n");
	fflush(stdout);
	exit(130);

}

void handle_SIGTERM(int __attribute__((unused))sig)
{
	free_buffer();
	exit_code = argv[1] ? atoi(argv[1]) : 0;
	free_args(argv);
	exit(exit_code);
}

void free_buffer(void)
{
	free(buffer);
	buffer = NULL;
}
