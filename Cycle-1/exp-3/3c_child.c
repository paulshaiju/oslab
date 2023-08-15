//Write a program using fork() system call to create two children of the same process i.e., Parent P having child process P1 and P2
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t p1,p2;
    p1=fork();
    if(p1==0)
    {
        printf("Pid of child p1 is %d\n",getpid());
        printf("Pid of parent of p1 is %d\n",getppid());

    }
    else
    {
        p2=fork();
        if(p2==0)
    {
        printf("Pid of 2nd child p2 is %d\n",getpid());
        printf("Pid of parent of p2 is %d\n",getppid());

    }
    else
    {
        printf("Pid of the parent process is %d\n",getpid());
    }
       
}
}

/* OUTPUT
Pid of the parent process is 2825
Pid of 2nd child p2 is 2827
Pid of parent of p2 is 2825
Pid of child p1 is 2826
Pid of parent of p1 is 1337
*/
