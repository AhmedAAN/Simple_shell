#include "shell.h"

/**
 * execute_commands - Executes the commands from the command line
 * @buffer: The input buffer containing the commands
 * @env: The environment variables
 * Return: 1 sucess, 0 error
 */
int execute_commands(char *buffer, char **env)
{
	char *args[MAX_ARGUMENTS], *filepath;
	int num_args, i;
	
	num_args = token_command(buffer, args);
	if (num_args == 0)
	{
		return (1);
	}
	for (i = 0; i < num_args; i++)
	{
		filepath = search_path(args[i]);
		if (check_filepath(filepath))
		{
			free(filepath);
			continue;
		}
		process(filepath, args[i], env);
		free(filepath);
	}
	strtok(buffer, "\0");
	return (1); 
}

/**
 * check_filepath - check if file path in null
 * @filepath: a pointer to the filepath
 * Return: 1 if filepath is NULL and 0 if not
 */
int check_filepath(char *filepath)
{
	if (filepath == NULL)
	{
		_printf("Error: command not found");
		_putchar('\n');
		return (1);
	}
	return (0);
}
/**
 * check_exit - check if the command is exit
 * @args: the arguments array
 * @run_flag: a pointer to the run flag
 * Return: 1 if the command is exit and 0 if not
 */
int check_exit(char **args, int *run_flag)
{
	if (strcmp(args[0], "exit") == 0)
	{
		*run_flag = 0;
		return (1);
	}
	return (0);
}


/**
 * main - Entry point for the shell program
 * @ac: the number of inputs
 * @av: the array of inputs
 * @env: the environmental variables
 * Return: Always 0
 */
int main(UNUSED int ac, UNUSED char **av, char **env)
{
	char *args[MAX_ARGUMENTS], *filepath, *buffer = NULL;
	size_t buf_size;
	int run_flag = 1, num_chars, num_args;

	while (run_flag)
	{
		if (isatty(STDIN_FILENO))
		{
			_printf("$ ");
			fflush(stdout);
		}
		num_chars = getline(&buffer, &buf_size, stdin);
		if (num_chars == 1)
			continue;
		if (num_chars == -1)
		{
			break;
		}
		execute_commands(buffer, env);
		if (check_exit(args, &run_flag))
			break;
	}
	free(buffer);
	return (0);
}
