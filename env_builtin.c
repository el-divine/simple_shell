#include "shell.h"

/**
 * _env - prints my current environment
 * @info: Structure containing potential arguments. For maintaining
 *	constant function prototype.
 * Return: Always 0
 */
int _env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. for maintaining
 * @name: env var name
 * Return: the value
 */
char *_getenv(const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
