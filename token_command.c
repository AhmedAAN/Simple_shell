#include "shell.h"


/**
 * _strtok - Tokenizes a string into tokens
 * @str: The string to tokenize
 * @delimiters: The delimiter characters
 * Return: A pointer to the next token, or NULL if no more tokens are found
 */
char *_strtok(char *str, const char *delimiters)
{
	static char *input = NULL;
	char *token;

	if (str != NULL)
	{
		input = str;
	}

	if (input == NULL)
	{
		return (NULL);
	}
	token = input;
	input += strspn(input, delimiters);
	if (*input == '\0')
	{
		input = NULL;
		return (NULL);
	}
	input += strcspn(input, delimiters);
	if (*input == '\0')
	{
		input = NULL;
	}
	else
	{
		*input++ = '\0';
	}

	return (token);
}


/**
 * token_command - tokenize the command into the args array
 *
 * @buffer: a pointer to the input buffer
 * @args: a pointer to the array of arguments
 *
 * Return: the number of arguments
 */
int token_command(char *buffer, char **args)
{
	int num_args = 0;
	char *arg;

	arg = _strtok(buffer, " \n");

	while (arg != NULL && num_args < MAX_ARGUMENTS - 1)
	{
		if (arg != NULL)
		{
			args[num_args] = arg;
		}
		num_args++;
		arg = _strtok(NULL, " \n");
	}

	args[num_args] = NULL;

	return (num_args);
}
