//Program to implement the indexed file allocation technique
#include<stdio.h>

int main()
{
    int n, m[20], i, j, sb[20], s[20], b[20][20], x;

    printf("Enter the number of files: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter starting block and size of file %d: ", i + 1);
        scanf("%d%d", &sb[i], &s[i]);
        printf("Enter blocks occupied by file %d: ", i + 1);
        scanf("%d", &m[i]);
        printf("Enter blocks of file %d: ", i + 1);
        for(j = 0; j < m[i]; j++)
            scanf("%d", &b[i][j]);
    }

    printf("\nFile\tindex\tlength\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", i + 1, sb[i], m[i]);
    }

    printf("\nEnter file name: ");
    scanf("%d", &x);
    printf("File name is: %d\n", x);
    i = x - 1;
    printf("Index is: %d\n", sb[i]);
    printf("Blocks occupied are: ");
    for(j = 0; j < m[i]; j++)
        printf("%3d", b[i][j]);

    return 0;
}

/*OUTPUT
Enter the number of files: 2
Enter starting block and size of file 1: 2 10
Enter blocks occupied by file 1: 3
Enter blocks of file 1: 4 5 3
Enter starting block and size of file 2: 4
10   
Enter blocks occupied by file 2: 3 
Enter blocks of file 2: 6 7 8

File    index   length
1       2       3
2       4       3

Enter file name: 1
File name is: 1
Index is: 2
Blocks occupied are:   4  5  3 */