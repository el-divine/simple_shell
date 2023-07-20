#include "shell.h"

int main(void)
{       
        int a = 2;
        int b = 4;
        int Sum = a+b;
        pid_t ppid;
        
 	ppid = getppid();
        write("Sum is %d\n", Sum);
        write("pid is %d\n", ppid);
        
        return 0;
}
