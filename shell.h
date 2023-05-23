#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGUMENTS 100

#define UNUSED __attribute__((unused))

extern char **environ;

int main(UNUSED int ac, UNUSED char **av, char **env);
int token_command(char *buffer, char **args);
char *search_path(char *filename);
int check_exit(char **args, int *run_flag);
void check_env(char **args, char **env);
int check_filepath(char *filepath);
void process(char *filepath, char *args[MAX_ARGUMENTS], char **env);
int _putchar(char c);
void _printf(char *c);

#endif
