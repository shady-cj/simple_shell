#include "main.h"

char *buffer = NULL;
char **argv = NULL;
char *cmd_str = NULL;
int exit_code = 0;
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
	size_t buf_size = 40;
	ssize_t ret_input;
	int interactive = isatty(STDIN_FILENO);

	signal(SIGTSTP, &handle_z);
	signal(SIGINT, &handle_SIGINT);
	signal(SIGTERM, &handle_SIGTERM);
	if (interactive)
		printf("$ ");
	do {
		ret_input = _getline(&buffer, &buf_size, stdout);
		if (ret_input == EOF)
		{
			if (interactive)
				printf("\n");
			continue;
		}	
		else
		{
			exit_code = dispatch(buffer, &cmd_str, &argv, interactive);
			re_initializer(&buffer, &buf_size, interactive, 40, 1);
		
		}
	} while (ret_input != EOF);
	free_buffer(&buffer);
}

/**
 * re_initializer - This function helps to avoid repetition while
 * reinitializing my variables after a process ends or a shell
 * command executes
 * @buffer: The existing string
 * @buf_size: A pointer to the buf_size initialize back to 40
 * @i: A pointer to the interator re_initialize to 0
 * @sh: To check if it's called in interactive mode or not
 * @buf_init: Buffer size to initialize with
 * @buf: buffer to free;
 * @main: it a 1 or 0 field that gives the information whether the call
 * is for the main buffer reset or not..
 * Return: void
 */
void re_initializer(char **buf, size_t *buf_size, int sh, int buf_init, int main)
{
	free_buffer(buf);
	*buf_size = buf_init;
	if (sh && main)
		printf("$ ");
}

void handle_z(int __attribute__((unused))sig)
{
	printf("\n$ ");
	fflush(stdout);
}
void handle_SIGINT(int __attribute__((unused))sig)
{
	printf("\n$ ");
	fflush(stdout);
}

void handle_SIGTERM(int __attribute__((unused))sig)
{
	free_buffer(&cmd_str);
	free_buffer(&buffer);
	free_args(argv);
	exit_code = argv[1] ? atoi(argv[1]) : 0;
	exit(exit_code);
}

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
