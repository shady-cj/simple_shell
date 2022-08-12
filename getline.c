#include "main.h"
/**
 * _getline - This gets the input from the standard input or a file
 * thus implementing
 * the getline function
 * @buffer: The buffer to write into
 * @buf_size: The size of the buffer
 * @STD: The file descriptor to read from.
 * Return: The amount of bytes written
 */
ssize_t _getline(char **buffer, size_t *buf_size, int STD)
{
	static ssize_t input;
	char c;
	char *str;
	int ret;

	if (STD < 2)
		fflush(stdout);
	str = alloc_str(*buf_size);
	input = 0;
	do {
		ret = read(STD, &c, 1);
		if (ret == -1 || (input == 0 && ret == 0))
		{
			free(str);
			return (-1);
		}
		if (c == '\n' || ret == 0)
		{
			continue;
		}
		if (input >= (ssize_t) *buf_size - 2)
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
