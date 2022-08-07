#include "main.h"
/**
 * This file implements the getline function in order to get the user
 * input from stream using the read sys call..
 *
 */

/**
 * _getline - This gets the input from the standard input thus implementing
 * the getline function
 * @buffer: The buffer to write into
 * @buf_size: The size of the buffer
 * @stream: The file stream in this case standard output
 * Return: The amount of bytes written
 */
ssize_t _getline(char **buffer, size_t *buf_size, FILE *stream)
{
	static ssize_t input;
	char c;
	char *str;
	int ret;

	fflush(stream);
	str = alloc_str(*buf_size);
	input = 0;
	do {
		ret = read(STDIN_FILENO, &c, 1);
		if (ret == -1 || (input == 0 && ret == 0))
		{
			free(str);
			return (-1);
		}
		if (c == '\n' || ret == 0)
		{
			continue;
		}
		if (input >= (ssize_t) *buf_size)
		{
			*buf_size += 4;
			str = realloc_str(str, *buf_size);
		}
		str[input] = c;
		input++;
	} while (c != '\n');
	str[input] = '\0';
	*buffer = str;
	return (input);
}
