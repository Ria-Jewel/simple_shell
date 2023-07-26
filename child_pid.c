#include "shell.h"

/**
 * run_child - Executes a command in a child process.
 * @args: The array of command and its arguments.
 * @str: The command string to be executed.
 * @env: The environment variables.
 * @count: The count of commands executed so far.
 */
void run_child(char **args, char *str, char **env, int count)
{
	int p_id = 0, wstatus = 0, werror = 0;

	p_id = fork();
	if (p_id == -1)
	{
		perror("Error: ");
		free_exit(args);
	}
	else if (p_id == 0)
	{
		run_exe(args, str, env, count);
		free_safe(args);
	}
	else
	{
		werror = waitpid(p_id, &wstatus, 0);
		if (werror == -1)
		{
			free_exit(args);
		}
		free_safe(args);
	}
}

