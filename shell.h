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
void execute(char *arr[], char *envp[]);
void print_environ(void);
void check_betty(void);
void token_path(char *arr[], char *y);
extern char **environ;
char *_strtok(char *s, const char *del);
char *_getline(void);
void _setenv(void);
void _unsetenv(char *var);
void _cd(char *arr[]);
void setenv2(char *var, char *l, int n);

#endif
