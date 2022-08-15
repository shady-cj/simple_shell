# simple_shell

## INTRODUCTION

The linux operating system is a very popular and powerful operating system with a lot of powerful features which is why it is the most used in fields like devops, cybersecurity, hacking etc... There are different distributions of Linux OS (CentOs, Kali Linux, Debian, Fedora, Ubuntu, RedHat) in which some of this distributions have sub distributions... An example of a Linux distro is **UBUNTU** which in turn has sub distros such as _Lubuntu_, _Kubuntu_ and _Xubuntu_.
This Project is about building a linux shell similar to the traditional linux terminal.. With a lot of functionality although not all.. using **C** programming Language.

This project combines different concept from C programming ranging from reading files, taking inputs reading directories etc... to a implement a simple shell with functionalities similar to that of /bin/sh

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
aliases2.c          env_utils.c       main.h           shell.c           verify_command.
```

### HANDLE ARGUMENTS WITH OR WITHOUT FULL PATH
It can also handle commands with arguments
```
$ /bin/ls -la
total 142
drwx------ 4 u0_a283 u0_a283  3488 Aug 12 12:48 .
drwx------ 5 u0_a283 u0_a283  3488 Jul 28 16:51 ..
drwx------ 7 u0_a283 u0_a283  3488 Aug 12 08:53 .git
-rw------- 1 u0_a283 u0_a283    92 Aug 11 13:21 AUTHORS
-rw------- 1 u0_a283 u0_a283  4992 Aug 12 08:33 BETTY_CHECK_ERRORS
-rw------- 1 u0_a283 u0_a283  3962 Aug 12 12:48 README.md
-rw------- 1 u0_a283 u0_a283  3304 Aug 12 11:01 aliases.c
-rw------- 1 u0_a283 u0_a283  2096 Aug 12 02:22 aliases2.c
-rwx------ 1 u0_a283 u0_a283    72 Aug  3 12:47 compile.sh
-rw------- 1 u0_a283 u0_a283   869 Aug 12 01:40 dir_cmds.c
-rw------- 1 u0_a283 u0_a283  3726 Aug 12 02:23 dispatch_cmd.c
-rw------- 1 u0_a283 u0_a283   937 Aug 11 14:57 env_operations.c
-rw------- 1 u0_a283 u0_a283  2996 Aug 12 02:20 env_utils.c
-rw------- 1 u0_a283 u0_a283  1534 Aug 12 01:40 execute_cmd.c
-rw------- 1 u0_a283 u0_a283   675 Aug 10 17:48 free_and_init.c
-rw------- 1 u0_a283 u0_a283   860 Aug 12 02:18 getline.c
-rw------- 1 u0_a283 u0_a283   681 Aug 12 08:51 main.c
-rw------- 1 u0_a283 u0_a283  3423 Aug 12 08:53 main.h
-rw------- 1 u0_a283 u0_a283   537 Aug 11 14:48 map_function.c
-rw------- 1 u0_a283 u0_a283  2233 Aug 10 14:21 mem_management.c
-rw------- 1 u0_a283 u0_a283   902 Aug 11 09:24 quit_cmds.c
-rwx------ 1 u0_a283 u0_a283 31352 Aug 12 08:54 shell
-rw------- 1 u0_a283 u0_a283  2349 Aug 12 08:51 shell.c
-rw------- 1 u0_a283 u0_a283  4088 Aug 12 02:25 string_utils.c
-rw------- 1 u0_a283 u0_a283    32 Aug 10 14:21 test.txt
drwx------ 2 u0_a283 u0_a283  3488 Aug  9 22:40 utils
-rw------- 1 u0_a283 u0_a283  1653 Aug 12 02:22 variables_handler.c
-rw------- 1 u0_a283 u0_a283  3147 Aug 11 09:19 verify_command.c
$ readlink -e shell 
/data/data/com.termux/files/home/ceejay/alx/simple_shell/shell
$
```

### HANDLE EXIT
#### WITHOUT EXIT NUMBER
```
$ exit
```
#### WITH EXIT NUMBER
```
$ exit 98
~/.../alx/simple_shell $ echo $?
98
`
```
#### THROWS ERROR IF AN INVALID CODE IS TYPED
```
$ exit -98
./shell: 1: exit: Illegal number: -98
$ exit 9d8
./shell: 1: exit: Illegal number: 9d8
```

### SUPPRESSES CONTROL C AND CONTROL Z
```
$ ^C
$ ^C
$ ^Z
$ ^Z
```
### ENV BUILT IN
```
$ env
SHELL=/data/data/com.termux/files/usr/bin/bash
COLORTERM=truecolor
HISTCONTROL=ignoreboth
PREFIX=/data/data/com.termux/files/usr
TERMUX_IS_DEBUGGABLE_BUILD=0
TERMUX_MAIN_PACKAGE_FORMAT=debian
PWD=/data/data/com.termux/files/home/ceejay/alx/simple_shell
TERMUX_VERSION=0.118.0
EXTERNAL_STORAGE=/sdcard
LD_PRELOAD=/data/data/com.termux/files/usr/lib/libtermux-exec.so
HOME=/data/data/com.termux/files/home
LANG=en_US.UTF-8
TERMUX_APK_RELEASE=F_DROID
DEX2OATBOOTCLASSPATH=/apex/com.android.art/javalib/core-oj.jar:/apex/com.android.art/javalib/core-libart.jar:/apex/com.android.art/javalib/okhttp.jar:/apex/com.android.art/javalib/bouncycastle.jar:/apex/com.android.art/javalib/apache-xml.jar:/system/framework/framework.jar:/system/framework/framework-graphics.jar:/system/framework/ext.jar:/system/framework/telephony-common.jar:/system/framework/voip-common.jar:/system/framework/ims-common.jar:/apex/com.android.i18n/javalib/core-icu4j.jar:/system/framework/trans-framework.jar:/system/framework/mediatek-telephony-base.jar:/system/framework/mediatek-telephony-common.jar:/system/framework/mediatek-common.jar:/system/framework/mediatek-framework.jar:/system/framework/mediatek-ims-common.jar:/system/framework/mediatek-ims-base.jar:/system/framework/mediatek-telecom-common.jar
TMPDIR=/data/data/com.termux/files/usr/tmp
ANDROID_DATA=/data
TERM=xterm-256color
ANDROID_I18N_ROOT=/apex/com.android.i18n
SHLVL=1
ANDROID_ROOT=/system
BOOTCLASSPATH=/apex/com.android.art/javalib/core-oj.jar:/apex/com.android.art/javalib/core-libart.jar:/apex/com.android.art/javalib/okhttp.jar:/apex/com.android.art/javalib/bouncycastle.jar:/apex/com.android.art/javalib/apache-xml.jar:/system/framework/framework.jar:/system/framework/framework-graphics.jar:/system/framework/ext.jar:/system/framework/telephony-common.jar:/system/framework/voip-common.jar:/system/framework/ims-common.jar:/apex/com.android.i18n/javalib/core-icu4j.jar:/system/framework/trans-framework.jar:/system/framework/mediatek-telephony-base.jar:/system/framework/mediatek-telephony-common.jar:/system/framework/mediatek-common.jar:/system/framework/mediatek-framework.jar:/system/framework/mediatek-ims-common.jar:/system/framework/mediatek-ims-base.jar:/system/framework/mediatek-telecom-common.jar:/apex/com.android.appsearch/javalib/framework-appsearch.jar:/apex/com.android.conscrypt/javalib/conscrypt.jar:/apex/com.android.ipsec/javalib/android.net.ipsec.ike.jar:/apex/com.android.media/javalib/updatable-media.jar:/apex/com.android.mediaprovider/javalib/framework-mediaprovider.jar:/apex/com.android.os.statsd/javalib/framework-statsd.jar:/apex/com.android.permission/javalib/framework-permission.jar:/apex/com.android.permission/javalib/framework-permission-s.jar:/apex/com.android.scheduling/javalib/framework-scheduling.jar:/apex/com.android.sdkext/javalib/framework-sdkextensions.jar:/apex/com.android.tethering/javalib/framework-connectivity.jar:/apex/com.android.tethering/javalib/framework-tethering.jar:/apex/com.android.wifi/javalib/framework-wifi.jar:/apex/com.transsion.mi.os.framework/javalib/os-framework.jar
ANDROID_TZDATA_ROOT=/apex/com.android.tzdata
TERMUX_APP_PID=4681
PATH=/data/data/com.termux/files/usr/bin
ANDROID_ART_ROOT=/apex/com.android.art
OLDPWD=/data/data/com.termux/files/home
_=./shell
```
This is a built-in command and different from the built-in command in the bin directory
Thus if the PATH variable is cleared the `env` command is summoned it wont through an error

### SETTING AND UNSETTING ENVIRONMENT VARIABLES
```
$ setenv NAME=PETER
$ env
SHELL=/data/data/com.termux/files/usr/bin/bash
COLORTERM=truecolor
HISTCONTROL=ignoreboth
PREFIX=/data/data/com.termux/files/usr
TERMUX_IS_DEBUGGABLE_BUILD=0
TERMUX_MAIN_PACKAGE_FORMAT=debian
PWD=/data/data/com.termux/files/home/ceejay/alx/simple_shell
TERMUX_VERSION=0.118.0
EXTERNAL_STORAGE=/sdcard
LD_PRELOAD=/data/data/com.termux/files/usr/lib/libtermux-exec.so
HOME=/data/data/com.termux/files/home
LANG=en_US.UTF-8
TERMUX_APK_RELEASE=F_DROID
DEX2OATBOOTCLASSPATH=/apex/com.android.art/javalib/core-oj.jar:/apex/com.android.art/javalib/core-libart.jar:/apex/com.android.art/javalib/okhttp.jar:/apex/com.android.art/javalib/bouncycastle.jar:/apex/com.android.art/javalib/apache-xml.jar:/system/framework/framework.jar:/system/framework/framework-graphics.jar:/system/framework/ext.jar:/system/framework/telephony-common.jar:/system/framework/voip-common.jar:/system/framework/ims-common.jar:/apex/com.android.i18n/javalib/core-icu4j.jar:/system/framework/trans-framework.jar:/system/framework/mediatek-telephony-base.jar:/system/framework/mediatek-telephony-common.jar:/system/framework/mediatek-common.jar:/system/framework/mediatek-framework.jar:/system/framework/mediatek-ims-common.jar:/system/framework/mediatek-ims-base.jar:/system/framework/mediatek-telecom-common.jar
TMPDIR=/data/data/com.termux/files/usr/tmp
ANDROID_DATA=/data
TERM=xterm-256color
ANDROID_I18N_ROOT=/apex/com.android.i18n
SHLVL=1
ANDROID_ROOT=/system
BOOTCLASSPATH=/apex/com.android.art/javalib/core-oj.jar:/apex/com.android.art/javalib/core-libart.jar:/apex/com.android.art/javalib/okhttp.jar:/apex/com.android.art/javalib/bouncycastle.jar:/apex/com.android.art/javalib/apache-xml.jar:/system/framework/framework.jar:/system/framework/framework-graphics.jar:/system/framework/ext.jar:/system/framework/telephony-common.jar:/system/framework/voip-common.jar:/system/framework/ims-common.jar:/apex/com.android.i18n/javalib/core-icu4j.jar:/system/framework/trans-framework.jar:/system/framework/mediatek-telephony-base.jar:/system/framework/mediatek-telephony-common.jar:/system/framework/mediatek-common.jar:/system/framework/mediatek-framework.jar:/system/framework/mediatek-ims-common.jar:/system/framework/mediatek-ims-base.jar:/system/framework/mediatek-telecom-common.jar:/apex/com.android.appsearch/javalib/framework-appsearch.jar:/apex/com.android.conscrypt/javalib/conscrypt.jar:/apex/com.android.ipsec/javalib/android.net.ipsec.ike.jar:/apex/com.android.media/javalib/updatable-media.jar:/apex/com.android.mediaprovider/javalib/framework-mediaprovider.jar:/apex/com.android.os.statsd/javalib/framework-statsd.jar:/apex/com.android.permission/javalib/framework-permission.jar:/apex/com.android.permission/javalib/framework-permission-s.jar:/apex/com.android.scheduling/javalib/framework-scheduling.jar:/apex/com.android.sdkext/javalib/framework-sdkextensions.jar:/apex/com.android.tethering/javalib/framework-connectivity.jar:/apex/com.android.tethering/javalib/framework-tethering.jar:/apex/com.android.wifi/javalib/framework-wifi.jar:/apex/com.transsion.mi.os.framework/javalib/os-framework.jar
ANDROID_TZDATA_ROOT=/apex/com.android.tzdata
TERMUX_APP_PID=4681
PATH=/data/data/com.termux/files/usr/bin
ANDROID_ART_ROOT=/apex/com.android.art
OLDPWD=/data/data/com.termux/files/home
_=./shell
NAME=PETER
$ unsetenv NAME
$ env
SHELL=/data/data/com.termux/files/usr/bin/bash
COLORTERM=truecolor
HISTCONTROL=ignoreboth
PREFIX=/data/data/com.termux/files/usr
TERMUX_IS_DEBUGGABLE_BUILD=0
TERMUX_MAIN_PACKAGE_FORMAT=debian
PWD=/data/data/com.termux/files/home/ceejay/alx/simple_shell
TERMUX_VERSION=0.118.0
EXTERNAL_STORAGE=/sdcard
LD_PRELOAD=/data/data/com.termux/files/usr/lib/libtermux-exec.so
HOME=/data/data/com.termux/files/home
LANG=en_US.UTF-8
TERMUX_APK_RELEASE=F_DROID
DEX2OATBOOTCLASSPATH=/apex/com.android.art/javalib/core-oj.jar:/apex/com.android.art/javalib/core-libart.jar:/apex/com.android.art/javalib/okhttp.jar:/apex/com.android.art/javalib/bouncycastle.jar:/apex/com.android.art/javalib/apache-xml.jar:/system/framework/framework.jar:/system/framework/framework-graphics.jar:/system/framework/ext.jar:/system/framework/telephony-common.jar:/system/framework/voip-common.jar:/system/framework/ims-common.jar:/apex/com.android.i18n/javalib/core-icu4j.jar:/system/framework/trans-framework.jar:/system/framework/mediatek-telephony-base.jar:/system/framework/mediatek-telephony-common.jar:/system/framework/mediatek-common.jar:/system/framework/mediatek-framework.jar:/system/framework/mediatek-ims-common.jar:/system/framework/mediatek-ims-base.jar:/system/framework/mediatek-telecom-common.jar
TMPDIR=/data/data/com.termux/files/usr/tmp
ANDROID_DATA=/data
TERM=xterm-256color
ANDROID_I18N_ROOT=/apex/com.android.i18n
SHLVL=1
ANDROID_ROOT=/system
BOOTCLASSPATH=/apex/com.android.art/javalib/core-oj.jar:/apex/com.android.art/javalib/core-libart.jar:/apex/com.android.art/javalib/okhttp.jar:/apex/com.android.art/javalib/bouncycastle.jar:/apex/com.android.art/javalib/apache-xml.jar:/system/framework/framework.jar:/system/framework/framework-graphics.jar:/system/framework/ext.jar:/system/framework/telephony-common.jar:/system/framework/voip-common.jar:/system/framework/ims-common.jar:/apex/com.android.i18n/javalib/core-icu4j.jar:/system/framework/trans-framework.jar:/system/framework/mediatek-telephony-base.jar:/system/framework/mediatek-telephony-common.jar:/system/framework/mediatek-common.jar:/system/framework/mediatek-framework.jar:/system/framework/mediatek-ims-common.jar:/system/framework/mediatek-ims-base.jar:/system/framework/mediatek-telecom-common.jar:/apex/com.android.appsearch/javalib/framework-appsearch.jar:/apex/com.android.conscrypt/javalib/conscrypt.jar:/apex/com.android.ipsec/javalib/android.net.ipsec.ike.jar:/apex/com.android.media/javalib/updatable-media.jar:/apex/com.android.mediaprovider/javalib/framework-mediaprovider.jar:/apex/com.android.os.statsd/javalib/framework-statsd.jar:/apex/com.android.permission/javalib/framework-permission.jar:/apex/com.android.permission/javalib/framework-permission-s.jar:/apex/com.android.scheduling/javalib/framework-scheduling.jar:/apex/com.android.sdkext/javalib/framework-sdkextensions.jar:/apex/com.android.tethering/javalib/framework-connectivity.jar:/apex/com.android.tethering/javalib/framework-tethering.jar:/apex/com.android.wifi/javalib/framework-wifi.jar:/apex/com.transsion.mi.os.framework/javalib/os-framework.jar
ANDROID_TZDATA_ROOT=/apex/com.android.tzdata
TERMUX_APP_PID=4681
PATH=/data/data/com.termux/files/usr/bin
ANDROID_ART_ROOT=/apex/com.android.art
OLDPWD=/data/data/com.termux/files/home
_=./shell
```


### CHANGE DIRECTORY.
By default cd is not present in the bin directory so exec doesn't recognize it.. so a built-in cd was implemented thus you can cd into directories just like the normal sh shell and displays errors if 
directory doesn't exist

#### CD TO A DIRECTORY THAT EXIST USING BOTH RELATIVE AND ABSOLUTE PATH
```
$ cd /bin
$ pwd
/system/bin
```
 USING RELATIVE PATH
```
$ cd ..
$ pwd
/data/data/com.termux/files/home/ceejay/alx
```

#### CD - , CD 
while running cd it keeps track of the present and old pwd thus cd - would take you back to the old pwd and cd takes you to the home directory
```
$ cd
$ pwd
/data/data/com.termux/files/home
$ cd -
/data/data/com.termux/files/home/ceejay/alx/simple_shell
$ pwd
/data/data/com.termux/files/home/ceejay/alx/simple_shell
```

### HANDLE COMMANDS SEPARATOR ';'
Running multiple commands is possible by using the **;** separator.. 
example

```
$ pwd; ls -la; cat shell.c
/data/data/com.termux/files/home/ceejay/alx/simple_shell
total 158
drwx------ 4 u0_a283 u0_a283  3488 Aug 12 13:56 .
drwx------ 5 u0_a283 u0_a283  3488 Jul 28 16:51 ..
drwx------ 7 u0_a283 u0_a283  3488 Aug 12 08:53 .git
-rw------- 1 u0_a283 u0_a283    92 Aug 11 13:21 AUTHORS
-rw------- 1 u0_a283 u0_a283  4992 Aug 12 08:33 BETTY_CHECK_ERRORS
-rw------- 1 u0_a283 u0_a283 17192 Aug 12 13:56 README.md
-rw------- 1 u0_a283 u0_a283  3304 Aug 12 11:01 aliases.c
-rw------- 1 u0_a283 u0_a283  2096 Aug 12 02:22 aliases2.c
-rwx------ 1 u0_a283 u0_a283    72 Aug  3 12:47 compile.sh
-rw------- 1 u0_a283 u0_a283   869 Aug 12 01:40 dir_cmds.c
-rw------- 1 u0_a283 u0_a283  3726 Aug 12 02:23 dispatch_cmd.c
-rw------- 1 u0_a283 u0_a283   937 Aug 11 14:57 env_operations.c
-rw------- 1 u0_a283 u0_a283  2996 Aug 12 02:20 env_utils.c
-rw------- 1 u0_a283 u0_a283  1534 Aug 12 01:40 execute_cmd.c
-rw------- 1 u0_a283 u0_a283   675 Aug 10 17:48 free_and_init.c
-rw------- 1 u0_a283 u0_a283   860 Aug 12 02:18 getline.c
-rw------- 1 u0_a283 u0_a283   681 Aug 12 08:51 main.c
-rw------- 1 u0_a283 u0_a283  3423 Aug 12 08:53 main.h
-rw------- 1 u0_a283 u0_a283   537 Aug 11 14:48 map_function.c
-rw------- 1 u0_a283 u0_a283  2233 Aug 10 14:21 mem_management.c
-rw------- 1 u0_a283 u0_a283   902 Aug 11 09:24 quit_cmds.c
-rwx------ 1 u0_a283 u0_a283 31352 Aug 12 08:54 shell
-rw------- 1 u0_a283 u0_a283  2349 Aug 12 08:51 shell.c
-rw------- 1 u0_a283 u0_a283  4088 Aug 12 02:25 string_utils.c
-rw------- 1 u0_a283 u0_a283    32 Aug 10 14:21 test.txt
drwx------ 2 u0_a283 u0_a283  3488 Aug  9 22:40 utils
-rw------- 1 u0_a283 u0_a283  1653 Aug 12 02:22 variables_handler.c
-rw------- 1 u0_a283 u0_a283  3147 Aug 11 09:19 verify_command.c
#include "main.h"

char *buffer = NULL;
char **argv = NULL;
char *cmd_str = NULL;
int exit_code = 0;
alias *alias_list_head = NULL;

/**
 * shell - This is the main function that implements the shell
 * @c: The number of argument from the command line
 * @filename: The filename if any was passed at the command line
 * Description: The shell function is the main function that connects other
 * functions it takes in the inputs and returns corresponding output as the
 * traditional shell would
 * Return: Status code.
 */

int shell(int c, char *filename)
{
        size_t buf_size = 40;
        ssize_t ret_input;
        int interactive = isatty(STDIN_FILENO), STD;

        STD = STDIN_FILENO;
        signal(SIGTSTP, &handle_z);
        signal(SIGINT, &handle_SIGINT);
        if (c > 1)
        {
                interactive = 0;
                STD = open(filename, O_RDONLY);
                if (STD == -1)
                {
                        perror("./shell");
                        return (errno);
                }
        }
        if (interactive)
                write(STDOUT_FILENO, "$ ", 2);
        do {
                ret_input = _getline(&buffer, &buf_size, STD);
                if (ret_input == EOF)
                {
                        if (interactive)
                                write(STDOUT_FILENO, "\n", 1);
                        continue;
                }
                else
                {
                        CODE_C++;
                        buffer = strip(buffer, ret_input);
                        buffer = sub_alias(buffer);
                        if (strlen(buffer) != 0)
                                exit_code = dispatch(buffer, &cmd_str, &argv, interactive);
                        else
                                exit_code = 0;
                        re_initializer(&buffer, &buf_size, interactive, 40, 1);
                }
        } while (ret_input != EOF);
        free_buffer(&buffer);
        free_aliases();
        if (STD > 2)
                close(STD);
        return (exit_code);
}

/**
 * handle_z - This handles call to ctrl Z to prevent from sending the process
 * background
 * @sig: The signal id
 * Return: void
 */
void handle_z(int __attribute__((unused))sig)
{
        printf("\n$ ");
        fflush(stdout);
}
/**
 * handle_SIGINT - Handles signal interrupt i.e when ctrl-c is typed
 * @sig: The signal id
 * Return: void
 */
void handle_SIGINT(int __attribute__((unused))sig)
{
        exit_code = 130;
        printf("\n$ ");
        fflush(stdout);
}
/**
 * handle_EXIT - Handles the termination signal when exit is called
 * @exit_no: The exit number
 * Return: void
 */
void handle_EXIT(int exit_no)
{
        free_buffer(&cmd_str);
        free_buffer(&buffer);
        free_args(argv);
        free_aliases();
        exit(exit_no == 0 ? exit_code : exit_no);
}

/**
 * get_exit_code - An helper function to get the current exit code
 * Return: the exit code
 */

int get_exit_code(void)
{
        return (exit_code);
}
```


### HANDLE THE _&&_ AND _||_ LOGICAL OPERATORS
```
$ pedn || pwd
./shell: 1: pedn: not found
/data/data/com.termux/files/home/ceejay/alx/simple_shell
$ pwd || ls
/data/data/com.termux/files/home/ceejay/alx/simple_shell
$ pwd && ls
/data/data/com.termux/files/home/ceejay/alx/simple_shell
AUTHORS             compile.sh        execute_cmd.c    map_function.c    string_utils.c
BETTY_CHECK_ERRORS  dir_cmds.c        free_and_init.c  mem_management.c  test.txt
README.md           dispatch_cmd.c    getline.c        quit_cmds.c       utils
aliases.c           env_operations.c  main.c           shell             variables_handler.c
aliases2.c          env_utils.c       main.h           shell.c           verify_command.c
$ pwg && ls
./shell: 4: pwg: not found
$ pwd || ls && find . -name shell.c
/data/data/com.termux/files/home/ceejay/alx/simple_shell
./shell.c
$
```

### THE USE OF _ALIAS_
#### USAGE
```
$ alias alias1=/bin/ls alias2=/bin/pwd alias3=/bin/echo
$ alias
alias1='/bin/ls'
alias2='/bin/pwd'
alias3='/bin/echo'
$ alias alias1 alias2 alias3=/bin/cat
alias1='/bin/ls'
alias2='/bin/pwd'
$ alias alias3
alias3='/bin/cat'
$
```

### HANDLE VARIABLE REPLACEMENT
```
$ echo $PATH
/data/data/com.termux/files/usr/bin
$ alias j=$PATH
$ aliad
./shell: 3: aliad: not found
$ alias
j='/data/data/com.termux/files/usr/bin'
$ echo $$
29200
$ echo $?
0
$ hdj
./shell: 7: hdj: not found
$ echo $?
127
$ cd /not-existing
./shell: 9: cd: can't cd to /not-existing
$ echo $?
1
$ echo $OLDPWD
/data/data/com.termux/files/home
$
```

### HANDLE COMMENTS

```
$ ls # pwd
AUTHORS             compile.sh        execute_cmd.c    map_function.c    string_utils.c
BETTY_CHECK_ERRORS  dir_cmds.c        free_and_init.c  mem_management.c  test.txt
README.md           dispatch_cmd.c    getline.c        quit_cmds.c       utils
aliases.c           env_operations.c  main.c           shell             variables_handler.c
aliases2.c          env_utils.c       main.h           shell.c           verify_command.c
```

### HANDLE FILE AS INPUT
The shell can read through files and execute commands line by line
The following example takes test.txt as input and execute the file

```
$ cat test.txt
ls
pwdhg
echo $? && echo $$



$ ./shell test.txt
AUTHORS             compile.sh        execute_cmd.c    map_function.c    string_utils.c
BETTY_CHECK_ERRORS  dir_cmds.c        free_and_init.c  mem_management.c  test.txt
README.md           dispatch_cmd.c    getline.c        quit_cmds.c       utils
aliases.c           env_operations.c  main.c           shell             variables_handler.c
aliases2.c          env_utils.c       main.h           shell.c           verify_command.c
./shell: 2: pwdhg: not found
127
29800
$
```

### NON-INTERACTIVE MODE.

The shell can also run in NON-INTERACTIVE mode
Example
```
~/.../alx/simple_shell $ echo "ls
> pwd
> echo $PATH" | ./shell
AUTHORS             compile.sh        execute_cmd.c    map_function.c    string_utils.c
BETTY_CHECK_ERRORS  dir_cmds.c        free_and_init.c  mem_management.c  test.txt
README.md           dispatch_cmd.c    getline.c        quit_cmds.c       utils
aliases.c           env_operations.c  main.c           shell             variables_handler.c
aliases2.c          env_utils.c       main.h           shell.c           verify_command.c
/data/data/com.termux/files/home/ceejay/alx/simple_shell
/data/data/com.termux/files/usr/bin
```

### NOTE

This shell does not implements all the regular shell functionality and should not be mistaken for the regular shell. It's just a simple clone that does the simple functionalities... some of the things it does not do include piping, redirection, single quotes and double quotes recognition... etc.. 
