#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
sem_t chop[5];
sem_t mutex;
char status[6]={'-','-','-','-','-'};
void printstatus()
{
	int i;
	printf("\n");
	for(i=0;i<5;i++)
		printf("   %c  ",status[i]);
}	
void *Philosopher(void *arg)
{
	long int num=(long int) arg;
	status[num]='H';
	printstatus();
	sem_wait(&mutex);
	sem_wait(&chop[num]);
	sleep(1);
	sem_wait(&chop[(num+1)%5]);
	status[num]='E';
	printstatus();
	sleep(1);
	sem_post(&chop[(num+1)%5]);
	sem_post(&chop[num]);
	sem_post(&mutex);
	status[num]='T';
	printstatus();
	pthread_exit(NULL);
}
int main()
{
	pthread_t phil[5];
	long int i,j;
	for(i=0;i<5;i++)
		sem_init(&chop[i],0,1);
	sem_init(&mutex,0,1);
	printf("\n");
	for(i=0;i<5;i++)
		printf(" P[%ld] ",i);
	for(i=0;i<5;i++)
		pthread_create(&phil[i],NULL,Philosopher,(void *)i);
	for(j=0;j<5;j++)
		pthread_join(phil[j],NULL);
}
