#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
int _setenv(const char *name, const char *value, int overwrite);
int get_env_index(const char *s);
char **get_key_value(char *s);
int main(void)
{
	int i;
	char *s;

	i = _setenv("PA", "test/path", 1);

	printf("%d\n", i);
	
	s = getenv("PA");
	printf("%s\n", s);
	
}
int _setenv(const char *name, const char *value, int overwrite)
{
	int idx;
	size_t str_size = strlen(name) + strlen(value) + 2;
	char *env;
	size_t i = 0, j = 0;

	if (name == NULL || value == NULL)
		return (-1);
	idx = get_env_index(name);
	env = malloc(sizeof(char) * str_size);
	
	if (env == NULL)
		return (-1);

	if (environ[idx])
	{
		if (overwrite == 0)
		{
			free(env);
			return (0);
		}
	}
	while (name[i])
	{
		env[i] = name[i];
		i++;
	}
	env[i++] = '=';
	while(value[j])
	{
		env[i] = value[j];
		i++;
		j++;
	}
	env[i] = '\0';
	environ[idx] = env;
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
