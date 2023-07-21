#include "shell.h"

int main(void)
{
	int a = 2;
	int b = 4;
	int Sum = a + b;
	pid_t ppid;
	ppid = getppid();
	_printf("Sum is %d\n", Sum);
	_printf("pid is %d\n", ppid);
	return (0);
}
