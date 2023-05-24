#include"main.h"
/**
 * _prompt - it prints prompt
 *
 *
 *Return:
 */

void _prompt(void)
{
	if (isatty(STDIN_FILENO))
		_puts2("$ ");
}

