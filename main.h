#ifndef MAIN_H
#define MAIN_H

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

void _parse(char *buf_line, char *buf_line_copy, char *argv[], char *delim);
void _prompt(void);
void _executecmd(char *argv[]);
char *get_path(char *cmd);
void _puts2(char *);
int _putchar2(char);


#endif


