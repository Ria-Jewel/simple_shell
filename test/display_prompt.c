#include "shell.h"
/**
 * display_prompt - Display the shell prompt.
 *
 * Return: void
 */
void display_prompt(void)
{
	/* Check if the standard input is associated with a terminal (isatty)*/
	if (isatty(STDIN_FILENO))
		/* Write the prompt symbol "$ " to the standard output*/
		write(STDOUT_FILENO, "$ ", 2);
}

/**
 * ch_dir - Change the current working directory.
 * @path: The new current working directory path.
 *
 * Return: 1 on success, 98 on failure.
 */
int ch_dir(const char *path)
{
	char *buf = NULL;

	if (!path)
		path = getcwd(buf, BUF_SIZE);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}

/**
 * exit_shell - Exit the shell with a specific exit status.
 * @args: Pointer to the array of arguments passed to the shell command.
 *
 * Return: void (exits the shell).
 */
void exit_shell(char **args)
{
	int num = 0;

	if (args[1] == NULL)
	{
		free_safe(args);
		exit(EXIT_SUCCESS);
	}

	num = _atoi(args[1]);
	free_safe(args);
	exit(num);
}

/**
 * print_error - Print an error message to the standard output.
 * @str: The name of the shell program (usually argv[0]).
 * @count: The number of command execution cycles.
 * @args: Pointer to the array of arguments passed to the shell.
 *
 * * Return: void
 */
void print_error(char *str, int count, char **args)
{
	char str_count;

	/* Write the program name (str) to the standard output. */
	write(STDOUT_FILENO, str, _strlen(str));
	write(STDOUT_FILENO, ": ", 2);

	/* Convert the count (int) to a character and write it */
	str_count = count + '0';
	write(STDOUT_FILENO, &str_count, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, args[0], _strlen(args[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
