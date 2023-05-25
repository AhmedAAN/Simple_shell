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
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (access(filepath, X_OK) == 0)
		{
			execve(filepath, args, env);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			_printf("%s: command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
