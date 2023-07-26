#include "shell.h"

/**
 * free_safe - Safely frees a null-terminated array of strings.
 * @args: The null-terminated array of strings to be freed.
 */
void free_safe(char **args)
{
	size_t i = 0;

	if (!args)
		return;

	/* Loop through the array and free each individual string. */
	while (args[i])
	{
		free(args[i]);
		i++;
	}

	/* Free the array itself. */
	free(args);
}

/**
 * free_exit - Frees a null-terminated array of strings and exits with failure.
 * @args: The null-terminated array of strings to be freed.
 */
void free_exit(char **args)
{
	size_t i = 0;

	if (!args)
		return;

	/* Loop through the array and free each individual string. */
	while (args[i])
	{
		free(args[i]);
		i++;
	}

	/* Free the array itself. */
	free(args);

	/* Exit the program with a failure status. */
	exit(EXIT_FAILURE);
}

