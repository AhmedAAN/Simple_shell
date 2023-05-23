#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - write a string
 * @c: a pointer to the string
 */
void _printf(char *c)
{
    int i = 0;
    while (c[i] != '\0')
    {
        _putchar(c[i]);
        i++;
    }
}
