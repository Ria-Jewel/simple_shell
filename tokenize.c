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
