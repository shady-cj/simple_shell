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
or 
Simply Run the executable file compile.sh
```
./compile.sh
./shell
```
## GETTING TO KNOW THE FILES
 * main.c - This file contains main function that contains the main() function.. The function calls the shell() function
 * shell.c - This file contains a function that embodies the main shell... This function initiates the call to other helper functions in order for the shell to be function
 * string_utils.c - This file contains helper functions that helps with string formatting such as splitting sentences into arrays and stripping strings of unncessary whitespaces
 * map_functions.c - This file contains an helper function that helps map a particular command to another function which implements the functionality
 * dir_cmds.c - This file contains functions that implements commands related to manipulating and interacting with directories
 * mem_management.c - Memory management is an important part of the project.. This file contains functions that abstract regularly used functions for memory allocation
 * aliases.c && aliases2.c - contains functions that handles the storing, substuting and managing aliases in the program
 * dispatch_cmd.c - Contains functions that checks for multiple commands such as pwd ; ls and also checking for logical AND and OR.
 * env_operation - Carries out setting of environment variables, unsetting and printing if env variables
 * env_utils - Contains helper functions that helps in carry out environment variable operation
 * execute_cmd - This contain the function that calls fork() to start up a new process if necessary and also call execvpe to execute in built commands.
 * free_and_init.c - This contains files that frees memory previously allocated variable and reinitializes variables that needs initialization after certain operations.
 * getline.c - Contains function that implements the getline() function in C but a little bit modified to suit the purpose of the calling functions
 * quit_cmd.c - Simply gets invoked when exit is called and checks to validate args passed to exit
 * variables_handler.c - Contains function that Helps in substituting environment variables when the $ is called
 * verify_command.c - Contains function that helps to verify if a command is present in the PATH env variables.
 * main.h - This file contains declaration of every functions and libraries needed throughout the project.

## FEATURES AND USAGE.

### SIMPLE COMMANDS
It can perform simple shell commands such as ls, pwd etc.

```
$ ls
AUTHORS             compile.sh        execute_cmd.c    map_function.c    string_utils.c
BETTY_CHECK_ERRORS  dir_cmds.c        free_and_init.c  mem_management.c  test.txt
README.md           dispatch_cmd.c    getline.c        quit_cmds.c       utils
aliases.c           env_operations.c  main.c           shell             variables_handler.c
aliases2.c          env_utils.c       main.h           shell.c           verify_command.c
