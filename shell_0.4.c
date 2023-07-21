#include "shell.h"

/**
 * int _exit - to exits the shell
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */

int _exit(info_t *info)

if (strstr(arg[0], "exit"))
{
	if (strcmp(arg[0], "exit") == 0)
	{
		exit(0);
	}
	int i = 0;

	while (arg[i] != '\0')
	{
		strcpy(&command[i], arg[i]);
		if (strcmp(command, "exit") == 0)
		{
			i++;
		}
		printf("Argument[i] = %s \n", command);
		execvp(command, argument);
		i++;
	}
	exit(0);
}
