//Write a program to create a thread T1. The main thread reads an int number and checks whether it is prime or not. T1 calculates the factorial of the same number at the same time.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *factorial(void *arg);

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    pthread_t tid;
    pthread_create(&tid, NULL, factorial, (void *)&num);
    int i, flag = 0;
    for(i = 2; i <= num/2; ++i) {
        if(num%i == 0) {
            flag = 1;
            break;
        }
    }
    if(num == 1) {
        printf("1 is not a prime number.\n");
    }
    else {
        if(flag == 0)
            printf("%d is a prime number.\n", num);
        else
            printf("%d is not a prime number.\n", num);
    }
    pthread_join(tid, NULL);
    return 0;
}

void *factorial(void *arg) {
    int num = *(int*)arg;
    int fact = 1, i;
    for(i = 1; i <= num; ++i) {
        fact *= i;
    }
    printf("Factorial of %d is %d.\n", num, fact);
    pthread_exit(NULL);
}

/* OUTPUT
user@cc06-desktop:~$ gcc 3f_factThread.c -o 3f_factThread -lpthread
user@cc06-desktop:~$ ./3f_factThread
Enter a number: 5
5 is a prime number.
Factorial of 5 is 120.
*/
