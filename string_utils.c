#include "main.h"
/**
 * This file contains helper function to modify strings
 */
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
	size_t buf_size_i = 20, buf_size_j = 20, i = 0, j = 0;
	char d = ' ';
	int found = 0;

	argv = malloc(sizeof(char *) * buf_size_i);
	if (argv == NULL)
		exit(1);
        argv[i] = alloc_str_arr(buf_size_j, argv, i, 0);
        while (*s)
        {
		if (i == buf_size_i)
		{
			buf_size_i += 20;
			argv = realloc(argv, buf_size_i);
		}
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
	argv[++i] = NULL;
	return (argv);
}
