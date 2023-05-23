#include "shell.h"

/**
 * process - excute process
 * @filepath: a pointer to the path to the file of the command
 * @args: a pointer to an array of args
 * @env: a pointer to the environmental variable
 */
void process(char *filepath, char *args[MAX_ARGUMENTS], char **env)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		_printf("Fork failed");
		_putchar('\n');
		exit(1);
	}
	else if (pid == 0)
	{
		execve(filepath, args, env);
		_printf("Error: command not found");
		_putchar('\n');
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}
