#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>

#define MAX_INPUT_SIZE 100

char **get_path();
int main(void);
void _printf(const char *message);
int line_interpreter(int token_count, char **envp);
int line_arguements(int token_count, char **envp);
size_t _strcspn(const char *s, const char *c);
int _atoi(char *str);
char *get_full_path(const char* str);
int _exit(char **line_tok);
int _env(info_t *info);
char *_getenv(info_t *info, const char *name);
int _getline(char *input, int size);
void clear_buffer(char *buffer);
char *mem_cpy(char *dest, char *src, int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int setenv(const char *name, const char *value, int overwrite);
int unsetenv(const char *name);
int populate_env_list(info_t *info);


#endif
