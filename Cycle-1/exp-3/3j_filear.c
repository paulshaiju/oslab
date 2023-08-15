/*
Write a C program that does the following.
a. Takes two filenames as argument.
b. Creates a file with name as second argument.
c. Copies content from file_1 to file_2.
d. First line of file_2 should be START and last line should be STOP.
*System calls used:
int open(const char *pathname, int flags) - open and possibly create a file
ssize_t read(int fd, void *buf, size_t count) - read from a file descriptor
ssize_t write(int fd, const void *buf, size_t count) - write to a file descriptor
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <stdlib.h>
int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Argument Error.\n");
		exit(0);
	}
	char *a = argv[1], *b = argv[2];
	char buf[128] = "";
	int rfd, wfd;
	// only read
	rfd = open(a, O_RDONLY);
	// only write
	wfd = open(b, O_WRONLY);
	if(wfd == -1)
		wfd = open(b, O_WRONLY | O_CREAT);
	write(wfd, "START\n", 6);
	while(read(rfd, buf, 1) > 0)
	{
		write(wfd, buf, strlen(buf));
	}
	write(wfd, "\nSTOP\n", 6);
	close(rfd);
	close(wfd);
	printf("Copied Contents from %s -> %s\n", a, b);
	return 0;
}
/*
s4csa1@cc3016-desktop:~$ ./3j_filear file1.txt file2.txt
Copied Contents from file1.txt -> file2.txt
file1.txt:
Hello from OS Lab
by S4 CSE(A)
Bye!
* file2.txt
* START
Hello from OS Lab
by S4 CSE(A)
Bye!
STOP
*/
