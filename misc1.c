#include "main.h"
/**
 * check_buf_size - An helper function to help reduce redundancy
 * @buf_size: The bufsize to check
 * @j:  a particluar iteration value
 * @str: The string to reallocate
 * Return: The new string if successful and NULL if not
 */
char *check_buf_size(size_t *buf_size, size_t j, char *str)
{
	if (j == *buf_size - 2)
	{
		*buf_size += 20;
		str = realloc(str, *buf_size);
		if (str == NULL)
			return (NULL);	
	}
	return (str);
}
/**
 * separate_symbol - This function helps to separate && and ||
 * from words.
 * @buffer: The string
 * @c: The current character
 * @n: The number to iterate
 * @i: The iteration count i
 * @j: The iteratoon j
 * @str: The string to copy into
 * @flag: The flag
 * @buf_size: The curenct buz_size
 * Return: 0 if success or 1 if faild
 */
int separate_symbol(char *buffer, char c,
		int *n, size_t *i,
		size_t *j, char *str,
		int *flag, size_t *buf_size)
{
	while (buffer[*i] == c && *n < 2 && buffer[*i])
	{
		if ((str = check_buf_size(buf_size, *j, str))
				== NULL)
			return (1);
		str[*j] = buffer[*i];
		*j = *j + 1;;
		*i = *i + 1;
		*n = *n + 1;
	}
	if (buffer[*i] == '\0')
		return (2);
	if (buffer[*i] != ' ')
	{
		str[*j] = ' ';
		*j = *j + 1;
	}
	*flag = 0;
	*n = 0;
	if (buffer[*i] == c)
	{
		*flag = 1;
		return (2);	
	}
	return (0);
}
