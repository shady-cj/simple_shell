#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
char **split(char *buffer);
char *strip(char *buffer, size_t size);
int main(void)
{
	char *buffer;
	size_t buf_size = 40, i;
	signed char c;
	char **argv;
	int child_p;

	argv = malloc(sizeof (char *) * 20);
	buffer = calloc(buf_size, sizeof(char));
	if (buffer == NULL)
		exit(1);
	printf("$ ");
	i = 0;
	do {
		c = getc(stdin);
		if (c == '\n')
		{
			buffer = strip(buffer, i);
			if (strlen(buffer) == 0)
			{
				free(buffer);
				buf_size = 40;
				i = 0;
				buffer = calloc(buf_size, sizeof(char));
				if (buffer == NULL)
					exit(1);
				printf("$ ");
				continue;
			}
			argv = split(buffer);
			child_p = fork();
			if (child_p == 0)
			{
				if (execvpe(argv[0], argv, NULL) == -1)
				{
					perror("Error");
					exit(1);
				}
			}
			else
			{
				wait(NULL);
			}
			free(buffer);
			buf_size = 40;
			i = 0;
			buffer = calloc(buf_size, sizeof(char));
			if (buffer == NULL)
				exit(1);
			printf("$ ");
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
			buffer = realloc(buffer, buf_size);
			if (buffer == NULL)
				exit(1);
		}
		buffer[i] = c;
		i++;
	} while (feof(stdin) == 0);
	return (0);
}


char **split(char *buffer)
{
	char *s = buffer;
	char **argv;
	size_t buf_size_i = 20, buf_size_j = 20, i, j;
	char d = ' ';
	int found = 0;

	argv = malloc(sizeof(char *) * buf_size_i);
	if (argv == NULL)
		exit(1);
	i = 0;
	j = 0;
        argv[i] = malloc(sizeof(char) * buf_size_j);
        if (argv[i] == NULL)
                exit(1);
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
                                i++;
                                argv[i] = malloc(sizeof(char) * buf_size_j);
                                j = 0;
                                if (argv[i] == NULL)
                                        exit(1);
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
					argv[i] = realloc(argv[i], buf_size_j);
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
