#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test(char **s)
{
	char **t = s;

	printf("%s -\n",  *t);
	t++;
	printf("%s --\n", *t);
	*t = "JOSEPH";
	free(*t);
	*t = NULL;
	t++;
	printf("%s ---\n", *t);
	*t = "HHHJSNN";
	printf("%s 00\n", *s);
}
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
typedef struct num_to_str
{
	int num;
	char c;
} num2str;

void _itoa(int num, char *str)
{
	num2str word[] = {
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
	int i = num, j, k = 0, h = 0;

	while (i)
	{
		j = i % 10;
		while (word[k].c)
		{
			if (j == word[k].num)
			{
				str[h] = word[k].c;
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
	printf("%s - j\n", str);
}
int main()
{
	char **argv = malloc(sizeof(char *) * 3);
	argv[0] = strdup("JOHN\0");
	argv[1] = strdup("PETER\0");
	argv[2] = NULL;

	char str[20];
	int j = 67637673;
	_itoa(j, str);

	puts(str);
	//test(&argv[0]);
	//printf("%c ls\n", 6);
	//printf("%s---\n", argv[1]);
	//printf("%s ---\n", argv[2]);
}

