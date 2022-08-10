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

int shell(void)
{
	size_t buf_size = 40;
	ssize_t ret_input;
	int interactive = isatty(STDIN_FILENO);

	signal(SIGTSTP, &handle_z);
	signal(SIGINT, &handle_SIGINT);
	if (interactive)
		write(STDOUT_FILENO, "$ ", 2);
	do {
		ret_input = _getline(&buffer, &buf_size, stdout);
		if (ret_input == EOF)
		{
			if (interactive)
				write(STDOUT_FILENO, "\n", 1);
			continue;
		}	
		else
		{
			buffer = strip(buffer, ret_input);
			if (strlen(buffer) != 0)
				exit_code = dispatch(buffer, &cmd_str, &argv, interactive);
			else
				exit_code = 0;
			re_initializer(&buffer, &buf_size, interactive, 40, 1);
		}
	} while (ret_input != EOF);
	free_buffer(&buffer);
	return (exit_code);
}

/**
 * handle_z - This handles call to ctrl Z to prevent from sending the process
 * background
 * @sig: The signal id
 * Return: void
 */
void handle_z(int __attribute__((unused))sig)
{
	printf("\n$ ");
	fflush(stdout);
}
/**
 * handle_SIGINT - Handles signal interrupt i.e when ctrl-c is typed
 * @sig: The signal id
 * Return: void
 */
void handle_SIGINT(int __attribute__((unused))sig)
{
	exit_code = 130;
	printf("\n$ ");
	fflush(stdout);
}
/**
 * handle_EXIT - Handles the termination signal when exit is called
 * @exit_no: The exit number
 * Return: void
 */
void handle_EXIT(int exit_no)
{
	free_buffer(&cmd_str);
	free_buffer(&buffer);
	free_args(argv);
	exit(exit_no == 0 ? exit_code : exit_no);
}

/**
 * get_exit_code - An helper function to get the current exit code
 * Return: the exit code
 */

int get_exit_code(void)
{
	return (exit_code);
}
