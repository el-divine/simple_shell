#include "shell.h"
/**
*get_path - function to read path
*Return: char pointer
*
*/

char **get_path()
{
	char *path, *token, *delim = ":";
	char **env_path;
	int token_count = 0;

	path = getenv("PATH");
	if (path == NULL)
	{
		_printf("Error: PATH environment variable not found.\n");
		exit();
	}

	token = strtok(path, delim);

	env_path = malloc((MAX_INPUT_SIZE + 1) * sizeof(char *));
	if (env_path == NULL)
	{
		_printf("Memory allocation failed\n");
		exit();
	}

	while (token && token_count < MAX_INPUT_SIZE)
	{
		env_path[token_count] = strdup(token);
		token = strtok(NULL, delim);
		token_count++;
	}
	env_path[token_count] = NULL;

	return (env_path);
}

/**
*get_full_path - function to read path
*@str: pointer parameter
*Return: char pointer
*
*/

char *get_full_path(const char *str)
{
	char **paths = get_path();
	int i = 0;
	char *full_path = NULL;
	size_t full_path_len;

	while (paths[i] != NULL)
	{
		full_path_len = strlen(paths[i]) + strlen("/") + strlen(str) + 1;
		full_path = malloc(full_path_len * sizeof(char));

		if (full_path == NULL)
		{
			_printf("Memory allocation failed\n");
			exit();
		}

		snprintf(full_path, full_path_len, "%s/%s", paths[i], str);
		if (access(full_path, F_OK) != -1)
		{
			free(paths);
			return (full_path);
		}

		free(full_path);
		full_path = NULL;
		i++;
	}

	free(paths);
	return (strdup(str));
}
