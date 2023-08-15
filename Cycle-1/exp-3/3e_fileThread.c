//Write a program to create two Threads T1 and T2.
//Thread T1 creates a file named Thread.txt while T2 writes
//“Hello its T2” into the Thread.txt
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *create_file(void *args) {
    FILE *fp = fopen("Thread.txt", "w");
    if (fp == NULL) {
        printf("Error creating file\n");
        exit(1);
    }
    fclose(fp);
    printf("Thread T1 created file Thread.txt\n");
    pthread_exit(NULL);
}

void *write_to_file(void *args) {
    FILE *fp = fopen("Thread.txt", "a");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp, "Hello its T2\n");
    fclose(fp);
    printf("Thread T2 wrote to file Thread.txt\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, create_file, NULL);
    pthread_create(&t2, NULL, write_to_file, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}

/* OUTPUT
user@cc06-desktop:~$ gcc 3e_primethread.c -o 3e_primethread -lpthread
user@cc06-desktop:~$ ./3e_primethread
Thread T1 created file Thread.txt
Thread T2 wrote to file Thread.txt
*/
