# simple_shell

## INTRODUCTION

The linux operating system is a very popular and powerful operating system with a lot of powerful features which is why it is the most used in fields like devops, cybersecurity, hacking etc... There are different distributions of Linux OS in which some of this distributions have sub distributions... An example of a Linux distro is **UBUNTU** which in turn has sub distros such as _Lubuntu_ and _Xubuntu_.
This Project is about building a linux shell similar to the traditional linux terminal.. With a lot of functionality although not all.. using **C** programming Language.

This project combines different concept from C programming ranging from reading files, taking inputsz reading directories etc...

## USAGE

To simply run this project and get it running.. Make sure all the files are in the same directory
`cd into the directory`
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
./shell
```

## GETTING TO KNOW THE FILES
 * main.c - This file contains main function that contains the main() function.. The function calls the shell() function
 * shell.c - This file contains a function that embodies the main shell... This function initiates the call to other helper functions in order for the shell to be function
 * string_utils.c - This file contains helper functions that helps with string formatting such as splitting sentences into arrays and stripping strings of unncessary whitespaces
 * map_functions.c - This file contains an helper function that helps map a particular command to another function which implements the functionality
 * dir_cmds.c - This file contains functions that implements commands related to manipulating and interacting with directories
 * mem_management.c - Memory management is an important part of the project.. This file contains functions that abstract regularly used functions for memory allocation
 * main.h - This file contains declaration of every functions and libraries needed throughout the project.

## IMPORTANT TO KNOW
This project is currently in development so there will be daily updates...


