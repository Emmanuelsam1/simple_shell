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

void tokenize(char *arr[], char *buf);
void execute(char **args, char **envp);
void print_environ(char *environ[]);
void parse_input(char *input, char **args);
void execute(char *arr[], char *envp[]);
void print_environ(void);
void check_betty(void);
void token_path(char *arr[], char *y);
extern char **environ;
char *_strtok(char *s, const char *del);
char *_getline(void);

#endif
