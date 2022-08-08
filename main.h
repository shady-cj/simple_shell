#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
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
 *
 * Environment Variables and Checking Paths and creating
 * Linked Lists from the PATH env variable
 *
 */
/**
 * struct path - Creates a structure for the directories present in the PATH
 * environment variables
 * @dir: The actual directory.
 * @link: A pointer to the next directory
 */
typedef struct path {
	char *dir;
	struct path *link;
} path_dir;
path_dir *add_path(path_dir **head, char *str);
char *get_env(char *s);
char **get_key_value(char *s);
char **split_path(char *s);
int check_path(path_dir *head, char *cmd);
int get_cmd_from_path(char *cmd);
void free_linked_path(path_dir *head);


/**
 * Memory Management
 */
char *alloc_str(size_t size);
char *realloc_str(char *buffer, size_t size);
char *alloc_str_arr(size_t size, char **arr, size_t idx, int type);
void free_args(char **argv);
void free_buffer(char **buffer);


/**
 * Resetting buffers
 */
void re_initializer(char **buf, size_t *buf_size, int sh, int buf_init, int main);

/**
 * Main Shell Function
 */

void shell(void);
void handle_SIGINT(int __attribute__((unused))sig);
void handle_SIGTERM(int __attribute__((unused))sig);
int is_dir_check(char *str);

/**
 * Getting user input
 */
ssize_t _getline(char **buffer, size_t *buf_size, FILE *stream);


/**
 * Command executors and dispatchers
 */
int execute(char *buffer, size_t i, char ***argv);
int dispatch(char *buffer, char **cmd, char ***argv, int interactive);

#endif
