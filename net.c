#include "shell.h"

/**
 *main- function to read shell command
 *@token_count: integer parameter
 *@envp: char pointer parameter
 *Return: 0 on Success
 **/
int main(int token_count, char **envp)
{
	bool flag = true;
	char *str = NULL;
	size_t str_size = 0;
	pid_t child_pid;
	char *token;
	char *delim = " ";
	char *child_argv[MAX_INPUT_SIZE];
	_printf("$ : ");
	while (flag)
	{
		if (getline(&str, &str_size, stdin) != -1)
		{
			str[_strcspn(str, "\n")] = '\0';
			child_pid = fork();
			if (child_pid == 0)
			{
				token_count = 0;
				token = strtok(str, delim);
				while (token)
				{
					child_argv[token_count] = token;
					token = strtok(NULL, delim);
					token_count++;
				}
				child_argv[token_count] = NULL;
				if (token_count == 1)
				{
					execve(child_argv[0], child_argv, envp);
					perror("./simple_shell");
					exit(1);
				}
				else
				{
					_printf("./simple_shell: No such file or directory\n");
					exit(1);
				}
			}
			else
			{
				wait(NULL);
				if (flag)
				{
					_printf("$ : ");
				}
			}
		}
		else
		{
			flag = false;
		}
	}
	free(str);
	return (0);
}
