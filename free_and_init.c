#include "main.h"
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
		write(STDOUT_FILENO, "$ ", 2);
}
