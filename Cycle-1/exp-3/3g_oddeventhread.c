/*
Write a program to create two Threads "Even" and "Odd". Thread "Even" calculates the sum of
even numbers and Thread "Odd" calculates the sum of odd numbers. The main thread should
display the even and odd numbers.
*/
#include<pthread.h>
#include<stdio.h>
#define NUM_THREADS 3
int je,jo,evensum=0,sumn=0,oddsum=0,evenarr[50],oddarr[50];
void *Even(void *threadid)
{
	int i,n;
	je=0;
	n=(int)threadid;
	for(i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			evenarr[je]=i;
			evensum=evensum+i;
			je++;
		}
	}
}
void *Odd(void *threadid)
{
	int i,n;
	jo=0;
	n=(int)threadid;
	for(i=0;i<=n;i++)
	{
		if(i%2!=0)
		{
			oddarr[jo]=i;
			oddsum=oddsum+i;
			jo++;
		}
	}
}
void *SumN(void *threadid)
{
	int i,n;
	n=(int)threadid;
	for(i=1;i<=n;i++)
	{
		sumn=sumn+i;
	}
}
int main()
{
	pthread_t threads[NUM_THREADS];

	int i,t;
	printf("Enter a number\n");
	scanf("%d",&t);
	pthread_create(&threads[0],NULL,Even,(void *)t);
	pthread_create(&threads[1],NULL,Odd,(void *)t);
	pthread_create(&threads[2],NULL,SumN,(void *)t);
	for(i=0;i<NUM_THREADS;i++)
	{
		pthread_join(threads[i],NULL);
	}
	printf("The sum of first N natural nos is %d\n",sumn);
	printf("The sum of first N even natural nos is %d\n",evensum);
	printf("The sum of first N odd natural nos is %d\n",oddsum);
	printf("The first N even natural nos are----\n");
	for(i=0;i<je;i++)
		printf("%d\n",evenarr[i]);
	printf("The first N odd natural nos are----\n");
	for(i=0;i<jo;i++)
		printf("%d\n",oddarr[i]);
	pthread_exit(NULL);
}
/*
* shaiju@Ubuntu:~$ ./a.out
Enter a number
10
The sum of first N natural nos is 55
The sum of first N even natural nos is 30
The sum of first N odd natural nos is 25
The first N even natural nos are----
2
4
6
8
10
The first N odd natural nos are----
1
3
5
7
9
shaiju@Ubuntu:~$
*/
