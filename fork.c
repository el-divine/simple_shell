#include "shell.h"

int main(void)
{
	pid_t pid;
	_printf("called fork if the command doesn’t exist\n");
	fork();
	if  (pid == -1)
	{
		perror("Unsuccessful\n");
		return (1);
	}
	_printf("Fork was called\n");
	return (0);
}
