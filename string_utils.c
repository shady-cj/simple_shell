#include "main.h"
/**
 * strip - This helper function takes a string an removes all whitespace
 * padding from the beginning and from the end
 * @buffer: The string to strip
 * @size: The length of the string to strip
 * Return: This return back the same string with the space already
 * stripped off
 */
char *strip(char *buffer, size_t size)
{
	size_t i = size - 1, j, k;

	if (size == 0)
		return (buffer);
	while (buffer[i] == ' ' && i > 0)
	{
		buffer[i] = '\0';
		i--;
	}
	j = 0;
	while (buffer[j] == ' ' && j < size)
		j++;

	if (j != 0)
	{
		k = 0;
		while (buffer[j])
		{
			buffer[k] = buffer[j];
			buffer[j] = '\0';
			k++;
			j++;
		}
		i = k - 1;
	}
	buffer[++i] = '\0';
	return (buffer);
}

/**
 * split - This helper function helps to split strings at every space into an
 * array of strings
 * @buffer: The string to splitted
 * Return: Returns a pointer to the array of strings
 */
char **split(char *buffer)
{
	char *s = buffer;
	char **argv;
	size_t buf_size_i = 120, buf_size_j = 20, i = 0, j = 0;
	char d = ' ';
	int found = 0;

	argv = malloc(sizeof(char *) * buf_size_i);
	if (argv == NULL)
		exit(1);
	argv[i] = alloc_str_arr(buf_size_j, argv, i, 0);
	while (*s)
	{
		if (*s == d)
		{
			if (!found)
			{
				argv[i][j] = '\0';
				i++;
				argv[i] = alloc_str_arr(buf_size_j, argv,
						i, 0);
				j = 0;
				found = 1;
			}
		}
		else
		{
			if (*s != '\n')
			{
				if (j == buf_size_j)
				{
					buf_size_j += 20;
					argv[i] = alloc_str_arr(buf_size_j,
							argv, i, 1);
				}
				argv[i][j] = *s;
				j++;
			}
			found = 0;
		}
		s++;
	}
	argv[i][j] = '\0';
	argv[++i] = NULL;
	return (argv);
}

/**
 * _itoa - Converts integers to strings
 * @num: The integer to convert
 * @str: The string to write into
 * Return: void
 */
void _itoa(int num, char *str)
{
	num2str converter[] = {
		{0, '0'},
		{1, '1'},
		{2, '2'},
		{3, '3'},
		{4, '4'},
		{5, '5'},
		{6, '6'},
		{7, '7'},
		{8, '8'},
		{9, '9'},
		{-1, '\0'},
	};
	int i = num, n, k = 0, h = 0;

	if (i == 0)
	{
		str[0] = '0';
		h++;
	}
	while (i)
	{
		n = i % 10;
		while (converter[k].c)
		{
			if (n == converter[k].num)
			{
				str[h] = converter[k].c;
				h++;
				break;
			}
			k++;
		}
		i /= 10;
		k = 0;
	}
	str[h] = '\0';
	_strrev(str, h);
}

/**
 * _strrev - Reverses the string
 * @str: The string to reverse
 * @n: The length of the str:
 * Return: void
 */
void _strrev(char *str, int n)
{
	int i = 0, l = n - 1;
	char c;

	while (i < l)
	{
		c = str[i];
		str[i] = str[l];
		str[l] = c;
		i++;
		l--;
	}
}
/**
 * check_space - This function checks for && and || and make sure
 * they are properly spaced
 * @buffer: The buffer
 * Description: This helps to separate commands and the logical
 * statements like && and || the flag variable in the function
 * helps to keep track of which of & and | has been encountered
 * while copying over the string. where flag is 1 it means & has
 * been encountered while flag is 2 it means | has being encountered
 * and if 0 then none have been encountered
 * Return: The newly created buffer
 */
char *check_space(char *buffer)
{
	char *str, c;
	size_t buf_size = strlen(buffer), i = 0, j = 0;
	int flag = 0, n = 0;

	str = malloc(sizeof(char) * buf_size);
	if (str == NULL)
		return (buffer);
	while (buffer[i])
	{
		if (j == buf_size)
		{
			buf_size += 20;
			str = realloc(str, buf_size);
			if (str == NULL)
				return (buffer);
		}
		if (buffer[i] == '&' || buffer[i] == '|')
		{
			c = buffer[i];
			if (buffer[i-1] != ' ')
			{
				n = flag;
				if (!flag)
					str[j++] = ' ';
				while (buffer[i] == c && n < 2 && buffer[i])
				{
					str[j++] = buffer[i];
					i++;
					n++;
				}
				if (buffer[i] == '\0')
					continue;
				if (buffer[i] != ' ')
					str[j++] = ' ';
				flag = 0;
				n = 0;
				if (buffer[i] == c)
				{
					flag = 1;
					continue;
				}
			}
			else
				flag = 1;
		}
		str[j] = buffer[i];
		j++;
		i++;
	}
	str[j] = '\0';
	free(buffer);
	return (str);
}
