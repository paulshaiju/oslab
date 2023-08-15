// Write a program to create a thread T1. The main process passes two numbers to T1. T1 calculates the sum of these numbers and returns the sum to the parent process for printing.
#include <stdio.h>
#include <pthread.h>
void *calculate(void *args) {
    int num1 = ((int*) args)[0];
    int num2 = ((int*) args)[1];
    int sum = num1 + num2;
    return (void*) sum;
}

int main() {
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    int args[2] = {num1, num2};
    void* sum;
    pthread_t t1;
    pthread_create(&t1, NULL, calculate, (void*) args);
    pthread_join(t1, &sum);

    printf("The sum of %d and %d is %d\n", num1, num2, (int) sum);

return 0;
}

/* OUTPUT
user@cc06-desktop:~$ gcc 3d_thread.c -o 3d_thread -lpthread                                                        ^
user@cc06-desktop:~$ ./3d_thread
Enter the first number: 5
Enter the second number: 16
The sum of 5 and 16 is 21

 */
