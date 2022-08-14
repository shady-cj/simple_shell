#include <stdio.h>
#include <stdlib.h>


void test(char *s)
{
	s[0] = 'A';
	s[1] = 'B';
	s[2] = 'C';
}
int main()
{
	char *s = malloc(40);

	test(s);

	printf("%s -string\n", s);

}
