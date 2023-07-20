#include "shell.h"

int main(void)
{
	int a = 2;
	int b = 4;
	int Sum = a+b;
	pid_t pid;

	pid = getpid();
	write("Sum is %d\n", Sum);
	write("pid is %d\n", pid);

	return 0;
}
