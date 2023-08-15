/*Write a program where first process sends a number to second process
and calculates the factorial of that number. (Use shared memory
concept)
*/
// Sender Process Program - ipcfactsend.c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
int main()
{

	key_t key = 12345;
	printf("Writing to Shared Memory (Key = %d)\n",key);

	int shmid = shmget(key, sizeof(int), 0666 |IPC_CREAT);
	printf("shmid:\t%d\n", shmid);
	void *shmad = shmat(shmid, NULL, 0);
	printf("shmad:\t%p\n", shmad);
	int n;
	printf("\nEnter the value of N:");
	scanf("%d", &n);
	sprintf(shmad, "%d", n);
	printf("\nWrite '%d' to SHM complete.\n\n", n);
	return 0;
}
/*
shaiju@Ubuntu:~$ gcc ipcfactsend.c -o ipcfactsend
shaiju@Ubuntu:~$ ./ipcfactsend
Writing to Shared Memory (Key = 12345)
shmid: 131080
shmad:0x7f0901f55000
Enter the value of N:5
Write '5' to SHM complete.
shaiju@Ubuntu:~$
*/
