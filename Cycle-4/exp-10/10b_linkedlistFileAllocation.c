//Program to implement the linked file allocation technique
#include<stdio.h>

struct file
{
    char fname[10];
    int start, size, block[10];
};

int main()
{
    struct file f[10];
    int i, j, n;

    printf("Enter the number of files: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter file name: ");
        scanf("%s", f[i].fname);
        printf("Enter starting block: ");
        scanf("%d", &f[i].start);
        f[i].block[0] = f[i].start;
        printf("Enter the number of blocks: ");
        scanf("%d", &f[i].size);
        printf("Enter block numbers: ");
        for(j = 1; j <= f[i].size; j++)
        {
            scanf("%d", &f[i].block[j]);
        }
    }

    printf("File\tstart\tsize\tblock\n");
    for(i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\t", f[i].fname, f[i].start, f[i].size);
        for(j = 1; j <= f[i].size - 1; j++)
            printf("%d--->", f[i].block[j]);
        printf("%d", f[i].block[j]);
        printf("\n");
    }

    return 0;
}

/*OUTPUT
Enter the number of files: 2
Enter file name: 1
Enter starting block: 5
Enter the number of blocks: 3
Enter block numbers: 4
1
2
Enter file name: 2
Enter starting block: 4
Enter the number of blocks: 6
Enter block numbers: 7
3
5
9
8
6
File    start   size    block
1       5       3       4--->1--->2
2       4       6       7--->3--->5--->9--->8--->6 */
