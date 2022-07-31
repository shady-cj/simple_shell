#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char **environ;
int _unsetenv(const char *name);
int get_env_index(const char *s);
char **get_key_value(char *s);
int main(void)
{
	int c;
	//char *argv[2] = {"env", NULL};
	c = _unsetenv("PATH");
	if (c == 0)
	{
		printf("get%s\n", getenv("PATH"));

	}
	else
	{
		printf("%d\n", c);
	}
//	execvpe("env", argv, environ);
	return (0);
}
int _unsetenv(const char *name)
{
	int ret;

	if (name == NULL)
		return (-1);
	ret = get_env_index(name);
	if (environ[ret] == NULL)
	{
		return (0);
	}
	else
	{
		ret++;
		while (environ[ret])
		{
			environ[ret - 1] = environ[ret];
			ret++;
		}
		environ[ret-1] = environ[ret];
	}
	return (0);

}

int get_env_index(const char *s)
{
	int i = 0;
	char **argv;
	while (environ[i])
	{
		argv = get_key_value(environ[i]);
		if (strcmp(argv[0], s) == 0)
		{
			return (i);
		}
		i++;
		free(argv[0]);
		free(argv[1]);
		free(argv);
		argv = NULL;
	}
	return (i);
}

char **get_key_value(char *s)
{
	char key[1024];
	char value[1024];
	int i = 0, j = 0;
	char **argv = malloc(sizeof(char *) * 3);

	while (s[i] != '=')
	{
		key[i] = s[i];
		i++;
	}
	key[i] = '\0';
	argv[0] = strdup(key);
	i++;
	while (s[i])
	{
		value[j] = s[i];
		j++;
		i++;
	}
	value[j] = '\0';
	argv[1] = strdup(value);
	argv[2] = NULL;
	return (argv);
}
