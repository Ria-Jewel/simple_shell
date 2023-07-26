#include "shell.h"

/**
 * _getpath - Get the dir from the PATH environment variable.
 * @env: Pointer to an array of environment variables.
 *
 * Return: Pointer to an array of directories in the PATH variable.
 */
char **_getpath(char **env)
{
	unsigned int i = 0;
	char **paths = NULL, *path_var = NULL;

	/* Find the PATH environment variable */
	path_var = strtok(env[i], "=");
	while (env[i])
	{
		/* Check if the environment variable is "PATH" */
		if (_strcmp(path_var, "PATH"))
		{
			/* Get the value of the PATH variable */
			path_var = strtok(NULL, "\n");
			/* Tokenize the value to get individual directories */
			paths = tokenize(path_var, ":");
			return (paths);
		}
		i++;
		path_var = strtok(env[i], "=");
	}
	return (NULL);
}

/**
 * run_exe - Execute an external command with full path or from PATH dir.
 * @args: Pointer to an array of command arguments.
 * @str: Name of the shell program.
 * @env: Pointer to an array of environment variables.
 * @count: Number of execution
 */
void run_exe(char **args, char *str, char **env, int count)
{
	char **paths = NULL, *full_path = NULL;
	unsigned int i = 0;
	struct stat bt;

	/* Check if the command is "env" to print environment variables */
	if (_strcmp(args[0], "env") != 0)
		print_env(env);

	if (stat(args[0], &bt) == 0)
	{
		if (execve(args[0], args, env) < 0)
		{
			perror(str);
			free_exit(args);
		}
	}
	else
	{
		/* Get directories from PATH environment variable */
		paths = _getpath(env);
		while (paths[i])
		{
			full_path = _strcat(paths[i], args[0]);
			i++;
			/* Check if the command exists in the current dir */
			if (stat(full_path, &bt) == 0)
			{
				if (execve(full_path, args, env) < 0)
				{
					perror(str);
					free_safe(paths);
					free_exit(args);
				}
				return;
			}
		}
		/* Command not found in any directory, print error message */
		print_error(str, count, args);
		free_safe(paths);
	}
}

/**
 * print_env - Prints environment variable
 * @env: Pointer to environment variable
 *
 * Return: void
 */
void print_env(char **env)
{
	size_t i = 0, len = 0;

	while (env[i])
	{
		/* Calculate the length of the current environment variable string */
		len = _strlen(env[i]);
		/* Write the environment variable string to stdout */
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
