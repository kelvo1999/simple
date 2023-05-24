#include"main.h"
/**
 * _executecmd - it execute command from user
 * @argv:pointer
 *Return:
 */

void _executecmd(char *argv[])
{
	char *cmd = NULL, *path = NULL;
	pid_t pid = fork();
	int status;

	if (argv)
	{
		cmd = argv[0];
		path = get_path(cmd);

		if (pid == -1)
		{
			perror("Error: Fork");
			exit(-1);
		}
		else if (pid == 0)
		{
			if (execve(path, argv, NULL) == -1)
			{
				_puts2(argv[0]);
				_puts2(": 0: Can't open ");
				_puts2(argv[1]);
				_putchar2('\n');
			exit(-1);
			}
		}
		else
			waitpid(pid, &status, 0);
	}
}


