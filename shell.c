#include "shell.h"

/**
 * main - Shell entry point
 * @ac: Number of arguments
 * @av: Pointer to arguments
 * @env: Pointer to enviroment variable
 *
 * Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	int count = 0;
	char *lineptr = NULL, **args = NULL;
	size_t num = 0;
	ssize_t get_chars = 0;

	(void)ac;

	do {
		count++;
		display_prompt();
		/* Read input from the user */
		get_chars = getline(&lineptr, &num, stdin);

		if (*lineptr == '\n')
			free(lineptr);
		else
		{
			lineptr[_strlen(lineptr) - 1] = '\0';

			/* Tokenize the input line into arguments */
			args = tokenize(lineptr, " \0");
			free(lineptr);

			/* Check the command entered by the user and execute accordingly */
			if (_strcmp(args[0], "exit") != 0)
				exit_shell(args);
			else if (_strcmp(args[0], "cd") != 0)
				ch_dir(args[1]);
			else
				run_child(args, av[0], env, count);
		}

		/* Flush the standard input stream */
		fflush(stdin);
		lineptr = NULL, num = 0;
	} while (1);

	if (get_chars == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
