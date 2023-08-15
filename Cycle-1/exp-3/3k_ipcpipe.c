/*Program to send a message from parent process to child process using pipe()
system call:
int pipe(int pipefd[2])
* pipe() function creates a unidirectional pipe for IPC. On success it return two file descriptors
pipefd[0] and pipefd[1].
* pipefd[0] is the reading end of the pipe.
* pipefd[1] is the writing end of the pipe.
*
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int fd[2],n;
	char buffer[100];
	pid_t p;
	pipe(fd); //creates a unidirectional pipe with two end fd[0] and fd[1]
	p=fork();
	if(p>0) //parent
	{
		printf("I am parent having id %d\n",getpid());
		printf("Parent Passing value to child\n");
		write(fd[1],"hello\n",6); //fd[1] is the write end of the pipe
		wait(NULL);
	}
	else // child
	{
		sleep(1);
		printf("I am child having id %d\n",getpid());
		printf("Child printing received value\n");
		n=read(fd[0],buffer,100); //fd[0] is the read end of the pipe
		write(1,buffer,n);
	}
}
/*
* shaiju@Ubuntu:~$ gcc ipcpipe.c -o ipcpipe
shaiju@Ubuntu:~$ ./ipcpipe
I am parent having id 29440
Parent Passing value to child
I am child having id 29441
Child printing received value
hello
shaiju@Ubuntu:~$
*/
