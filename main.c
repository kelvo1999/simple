#include "main.h"
/**
 *_puts2 - prints string
 *@str: the string to be printed
 *
 * Return:
 */
void _puts2(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar2(str[i]);
		i++;
	}
}

/**
 * _putchar2 - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 *
 */

int _putchar2(char c)
{
	return (write(1, &c, 1));
}


/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j;
	char *buf_line = NULL, *buf_line_copy = NULL;
	char *argv[80];
	char *delim = " \n";
	size_t line_size = 0;
	ssize_t bytes_read;

	while (1)
	{
		_prompt();
		bytes_read = getline(&buf_line, &line_size, stdin);
		if (bytes_read == -1)
		{
			perror("Error: unable to read line");
			return (-1);
		}
		else
		{
			buf_line[strlen(buf_line) - 1] = '\0';
			buf_line_copy = malloc(sizeof(char) * bytes_read);
			if (buf_line_copy == NULL)
			{
				perror("Error: memory allocation Error");
				return (-1);
			}
			strcpy(buf_line_copy, buf_line);
			_parse(buf_line, buf_line_copy, argv, delim);
			_executecmd(argv);
		}
	}
	free(buf_line);
	free(buf_line_copy);
	return (0);
}

