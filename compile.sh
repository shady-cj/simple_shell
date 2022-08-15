#!/bin/bash
if [ -z "$1" ]
then
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
else
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o $1
fi
