//Using C, create a new process and replace the child process with the "ps" process. (use execl() system call).
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid;
    pid=fork();
    if(pid==0)
    {
        execl("/bin/ps","ps",NULL);
        printf("child  id %d\n",getpid());

    }
    else
    {
        wait(NULL);
        printf("parent id %d\n",getpid());
    }
}

/*OUTPUT
  PID TTY          TIME CMD
 2766 pts/1    00:00:00 sh
 2767 pts/1    00:00:00 sh
 2769 pts/1    00:00:00 3b_replace
 2770 pts/1    00:00:00 ps
parent id 2769
*/
