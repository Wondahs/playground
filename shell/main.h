#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

extern char **environ;

char *_getenv(char *name);
int _strlen(char *c);
int _strncmp(char *s1, char *s2, int n);
char *_strchr(char *s, char c);

#endif /* MAIN_H */

