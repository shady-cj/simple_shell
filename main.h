#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct cmd_opt - Defines a set of other commands that cannot be taken care
 * of by the exec functions
 * @cmd_type: The command type such as 'cd' etc..
 * @func: Pointer to a function that implements the functionality
 */
typedef struct cmd_opt 
{
	char *cmd_type;
	void (*func)(char **argv);
} cmd;

/**
 * Commands Helper functions
 */
void handle_cd(char **argv);
void handle_exit(char **argv);
void handle_setenv(char **argv);
void handle_unsetenv(char **argv);


void (*map_cmd(char *str))(char **argv);
/**
 * Strings Helper Functions
 */
char *strip(char *buffer, size_t size);
char **split(char *buffer);

/**
 * Memory Management
 */
char *alloc_str(size_t size);
char *realloc_str(char *buffer, size_t size);
char *alloc_str_arr(size_t size, char **arr, size_t idx, int type);
void free_args(char **argv);


/**
 * Resetting
 */
void re_initializer(char **buffer, size_t *buf_size, size_t *i, int interactive);

/**
 * Main Shell Function
 */

void shell(void);
#endif
