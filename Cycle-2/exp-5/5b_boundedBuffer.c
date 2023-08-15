// 5. b) Simulate Bounded-buffer (or Producer-Consumer) problem solution using Semaphore
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
sem_t empty,full;
pthread_mutex_t mutex;
int buffer[5];
int count=0;
void*producer(void*arg)
{
    long int num=(long int)arg;
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    buffer[count]=rand()%10;
    printf("\n Producer %ld Produced: %d",num+1,buffer[count]);
    count++;
    sleep(1);
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    pthread_exit(NULL);
}
void*consumer(void*arg)
{
    long int num=(long int)arg;
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    count--;
    printf("\n consumer %ld consumed: %d",num+1,buffer[count]);
    sleep(1);
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    pthread_exit(NULL);
}
int main()
{
    int np,nc;
    pthread_t p[10],c[10];
    unsigned long int i,j,k,l;
    printf("Enter number of producers and number of consumers");
    scanf("%d %d",&np,&nc);
    sem_init(&empty,0,5);
    sem_init(&full,0,0);
    pthread_mutex_init(&mutex,NULL);
    for(i=0;i<np;i++)
        pthread_create(&p[i],NULL,producer,(void*)i);
    for(j=0;j<nc;j++)
        pthread_create(&c[j],NULL,consumer,(void*)j);
    for(k=0;k<np;k++)
        pthread_join(p[k],NULL);
    for(l=0;l<nc;l++)
        pthread_join(c[l],NULL);
}

/*OUTPUT
Enter number of producers and number of consumers4 3

 Producer 1 Produced: 3
 Producer 2 Produced: 6
 Producer 3 Produced: 7
 Producer 4 Produced: 5
 consumer 1 consumed: 5
 consumer 3 consumed: 7
 consumer 2 consumed: 6 */
