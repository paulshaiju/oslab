//Create a new process and print its process id and its parent's process id in C (use fork() and wait() system call).
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid;
    pid=fork();
    if(pid==0)
    {
        printf("child  id %d\n",getpid());
        printf("parent id %d\n",getppid());
    }
    else
    {
        wait(NULL);
        printf("child id %d\n",pid);                                                          
        printf("parent id %d\n",getpid());
    }
}

/*
OUTPUT
child  id 2700
parent id 2699
child id 2700
parent id 2699
*/
