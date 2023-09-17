#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#define MAX_ARGS 128

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "printf.h"
#include <fcntl.h>
#include <string.h>

extern char **environ;

/**
 * struct Buffer - Holds information for buffer used with _getline.
 * @data: Buffer.
 * @index: Current position in buffer
 * @count: Number of bytes read
 *
 */
struct Buffer
{
	char data[BUFFER_SIZE];
	ssize_t index;
	ssize_t count;
};

typedef struct Buffer buff_t;

/**
 * struct Commands - Holds information about strings comtaining commands
 * @args: Arguments
 * @arg_count: Number of arguments
 *
 */
typedef struct Commands
{
	char *args[MAX_ARGS];
	int arg_count;
} cmd_t;

ssize_t _getline(char **lineptr, int *n, int fd, buff_t *buf);
char *_getenv(char *name);
int _strlen(char *c);
int _strncmp(char *s1, char *s2, int n);
char *_strchr(char *s, char c);
char *_strdup(char *s);
char *_strcat(char *dest, char *src);
char *_strtok(char *str, char *delim);
char *_strcpy(char *dest, char *src);
char *checkPath(char *cmd);
char *getPrompt(cmd_t *cmmds, cmd_t *args);
void execute(char *args[]);
int tokenize_cmd(char *cmd, char *args[], char *delim);
void cl_exec(cmd_t *args, int cmd_count, char *arg, bool Path);
char *replace_char(char *str, char c, char s);
int exit_atoi(char *str);
void _ext(cmd_t *cmmds, cmd_t *args, int cCt, int idx, char *arg, bool Path);
void free_args(char *args[], int num_token);
int count_slash(char *str);
char *abs_path(char *str);
ssize_t read_buffer(int fd, buff_t *buf);
char *_realloc(char **lineptr, int n, ssize_t tBytesRead);
cmd_t *init_cmd_t();
void looper(cmd_t *cmmds, cmd_t *args, char *argv_0, int *cmd_count);
char *read_file(char *input_file);
char *rmv_space(char *cmd);
char *rmv_double(char *cmd, char c);

#endif /* MAIN_H */