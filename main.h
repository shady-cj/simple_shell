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
#include <errno.h>

/**
 * alias_struct - Defines an alias structure for the shell env
 * @name: The name of the alias
 * @value: The value to the alias that is set
 * Description: Defines a structure to create a linked list in order
 * to store the alias in the shell environment
 */
typedef struct alias_struct
{
	char *name;
	char *value;
	struct alias_struct *link;
} alias;



/* GLOBAL VARIABLES */

extern alias *alias_list_head;
extern char *P_NAME;
extern size_t CODE_C;




void handle_z(int sig);
/**
 * struct cmd_opt - Defines a set of other commands that cannot be taken care
 * of by the exec functions
 * @cmd_type: The command type such as 'cd' etc..
 * @func: Pointer to a function that implements the functionality
 */
typedef struct cmd_opt
{
	char *cmd_type;
	int (*func)(char **argv);
} cmd;



int handle_cd(char **argv);
int handle_exit(char **argv);
int handle_setenv(char **argv);
int handle_unsetenv(char **argv);
int handle_alias(char **argv);
int print_env(char **argv);

int (*map_cmd(char *str))(char **argv);



char *strip(char *buffer, size_t size);
char **split(char *buffer);


/**
 * struct num_to_str - Helps to create a structure that maps numbers to
 * their corresponding equivalent in character.
 * @num: The number
 * @c: Equivalent of @num in string
 */
typedef struct num_to_str
{
	int num;
	char c;
} num2str;
void _strrev(char *str, int n);
void _itoa(int num, char *str);




/**
 * struct path - Creates a structure for the directories present
 * in the PATH
 * environment variables
 * @dir: The actual directory.
 * @link: A pointer to the next directory
 */
typedef struct path
{
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


char *alloc_str(size_t size);
char *realloc_str(char *buffer, size_t size);
char *alloc_str_arr(size_t size, char **arr, size_t idx, int type);
void free_args(char **argv);
void free_buffer(char **buffer);




void re_initializer(char **buf, size_t *buf_size, int sh,
		int buf_init, int main);



int shell(int, char *);
void handle_SIGINT(int __attribute__((unused))sig);
void handle_EXIT(int exit_no);
int get_exit_code(void);



ssize_t _getline(char **buffer, size_t *buf_size, int STD);



int execute(char *buffer, size_t i, char ***argv);
int execute_helper(char **argv);
int dispatch(char *buffer, char **cmd, char ***argv, int interactive);
void re_init_arr(char **arr);
int parse_cmd(char **argv);
void parse_cmd_helper_1(size_t *j, size_t *i, int *type,
		int *lor, char **arr, int flag);
int is_dir_check(char *str);



char **variable_substitution(char **argv);
void check_for_variable(char *cmd_str, char *str);



int store_aliases(char **argv);
int print_aliases(void);
char *get_alias_name(char *str, int *sf);
char *get_alias_value(char *str);
int search_alias(char *name);
int handle_alias(char **argv);
int add_alias_to_list(char *name, char *value);
void free_aliases(void);
char *sub_alias(char *buffer);
char *get_alias(char *str);

char *check_space(char *);
#endif
