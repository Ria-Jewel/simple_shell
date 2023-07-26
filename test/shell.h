#ifndef SHELL_H
#define SHELL_H

#define BUF_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* Function prototypes */

/* Tokenizes a given string using the provided delimiter characters. */
char **tokenize(char *buffer, const char *s);

/* Gets the PATH directories from the environment variables. */
char **_getpath(char **env);

/* Concatenates two strings and returns the result. */
char *_strcat(char *dest, char *src);

/* Copies the source string to the destination buffer. */
char *_strcpy(char *dest, char *src);

/* Changes the current working directory to the specified path. */
int ch_dir(const char *path);

/* Calculates the length of a given string. */
int _strlen(char *s);

/* Compares two strings and returns the difference. */
int _strcmp(char *s1, char *s2);

/* Converts a string to an integer. */
int _atoi(char *s);

/* Displays the prompt for the shell. */
void display_prompt(void);

/* Exits the shell gracefully, freeing allocated memory. */
void exit_shell(char **args);

/* Executes a command in a child process. */
void run_child(char **args, char *str, char **env, int count);

/* Executes a command in the current process. */
void run_exe(char **args, char *str, char **env, int count);

/* Safely frees a null-terminated array of strings. */
void free_safe(char **args);

/* Safely frees a null-terminated array of strings and exits with failure. */
void free_exit(char **args);

/* Handles end-of-file condition for user input. */
void _EOF(char *str);

/* Prints the environment variables. */
void print_env(char **env);

/* Prints an error message along with the command and its arguments. */
void print_error(char *str, int count, char **args);

/* Handles the signal generated when Ctrl + C is pressed. */
void handle_signal(int input);

#endif /* SHELL_H */

