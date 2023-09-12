#ifndef MAIN_H
#define MAIN_H

#define MAX_ARGS 128

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "printf.h"

extern char **environ;

ssize_t _getline(char **lineptr, int *n, int fd);
char *_getenv(char *name);
int _strlen(char *c);
int _strncmp(char *s1, char *s2, int n);
char *_strchr(char *s, char c);
char *_strdup(char *s);
char *_strcat(char *dest, char *src);
char *_strtok(char *str, char *delim);
char *_strcpy(char *dest, char *src);
char *checkPath(char *cmd);
char *getPrompt(void);
void execute(char *args[]);
int tokenize_cmd(char *cmd, char *args[]);
void cl_exec(int tok_count, char *args[], int cmd_count, char *arg, bool Path);
char *rmv_space(char *cmd);
int exit_atoi(char *str);
void sh_exit(char *args[], int i, int cmd_count, char *arg, bool Path);
void free_args(char *args[], int num_token);
int count_slash(char *str);
char *abs_path(char *str);

#endif /* MAIN_H */

