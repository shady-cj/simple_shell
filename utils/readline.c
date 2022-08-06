#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char c;
	char buffer[300];
	ssize_t ret;
	size_t i = 40, inp = 0;
	printf("# ");
	fflush(stdout);
	
	do {
		ret = read(STDIN_FILENO, &c, 1);
		if (ret == 0)
			break;
		if (c == '\n')
			continue;
		buffer[inp] = c;
		inp++;
	} while(c != '\n');
	buffer[inp] = '\0';
	printf("%s %lu bytes\n", buffer, inp);
}
