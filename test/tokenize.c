#include "shell.h"

/**
 * tokenize - Split and create a full string command.
 * @buf: Pointer to the input string.
 * @str: Delimiter for strtok.
 *
 * Return: Pointer to an array of strings with the tokenized command
 */
char **tokenize(char *buf, const char *str)
{
	char *token = NULL, **args = NULL;
	size_t buf_size = 0;
	int i = 0;

	/* Check if the input buffer is NULL. */
	if (!buf)
		return (NULL);

	buf_size = _strlen(buf);

	args = malloc(sizeof(char *) * (buf_size + 1));
	if (args == NULL)
	{
		perror("Allocation error");
		free(buf);
		free_safe(args);
		exit(EXIT_FAILURE);
	}
	/* Tokenize the input buffer using strtok. */
	token = strtok(buf, str);
	while (token != NULL)
	{
		/* Allocate memory for each token (string) and store it in the args array.*/
		args[i] = malloc(_strlen(token) + 1);
		if (args[i] == NULL)
		{
			perror("Allocation error");
			free_safe(args);
			return (NULL);
		}
		/* Copy the token (string) into the args array. */
		_strcpy(args[i], token);
		token = strtok(NULL, str);
		i++;
	}
	args[i] = NULL;
	return (args);
}

/**
 * _EOF - Handles end-of-file condition for user input.
 * @str: Pointer to the input string to be freed.
 *
 * Return: None.
 */
void _EOF(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}

	/* Check if the input is being read from a terminal */
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(str);
	exit(EXIT_SUCCESS);
}
/**
 * handle_signal - Handles the signal generated when Ctrl + C is pressed.
 * @input: The signal number (unused).
 *
 * Return: void
 */
void handle_signal(int input)
{
	(void)input;
	write(STDOUT_FILENO, "\n$ ", 4);
}
