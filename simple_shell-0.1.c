#include "shell.h"

/**
 *main- function to read shell command
 *@token_count: integer param
 *@envp: char pointer param
 *Return: 0 on Success
 **/
int main(int argc, char *argv[],  char **envp)
{
	bool flag = true;
	char *str = NULL, prompt = "$: ";
	size_t str_size = 0;
	size_t bytes;
	pid_t child_pid;
	char *token;
	char *delim = " ";
	char *child_argv[MAX_INPUT_SIZE];

	write [STDOUT_FILENO, prompt, 2];

	while (flag)
	{
		if (getline(&str, &str_size, stdin) != -1)
		{
			str[_strcspn(str, "\n")] = '\0';
			child_pid = fork();
		}
		if (child_pid == 0)
		{
			token_count = 0;
			token = strtok(str, delim);
		}
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
			write("./simple_shell: No such file or directory\n");
			exit(1);
		}
		else
		{
			wait(NULL);
		}
		if (flag)
		{
			write("$: ");
		}
		else
		{
			flag = false;
		}
	}
	free(str);
	return (0);
}
