//Program to simulate the sequential file allocation technique
#include <stdio.h>

int main() {
    int n, i, j, b[20], sb[20], t[20], x, c[20][20];

    printf("Enter the number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the number of blocks occupied by file %d: ", i + 1);
        scanf("%d", &b[i]);
        printf("Enter the starting block of file %d: ", i + 1);
        scanf("%d", &sb[i]);
        t[i] = sb[i];
        for (j = 0; j < b[i]; j++)
            c[i][j] = sb[i]++;
    }

    printf("\nFilename\tStart block\tLength\n");
    for (i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\n", i + 1, t[i], b[i]);

    printf("\nEnter the file name: ");
    scanf("%d", &x);
    printf("File name is: %d\n", x);
    printf("Length is: %d\n", b[x - 1]);
    printf("Blocks occupied: ");
    for (i = 0; i < b[x - 1]; i++)
        printf("%4d", c[x - 1][i]);

    return 0;
}

/*OUTPUT
Enter the number of files: 2
Enter the number of blocks occupied by file 1: 4
Enter the starting block of file 1: 5
Enter the number of blocks occupied by file 2: 3
Enter the starting block of file 2: 3

Filename        Start block     Length
1               5               4
2               3               3

Enter the file name: 1    
File name is: 1
Length is: 4
Blocks occupied:    5   6   7   8 */