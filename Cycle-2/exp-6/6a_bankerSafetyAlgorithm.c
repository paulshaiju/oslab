// 6. a) Write a C program to implement Banker's Algorithm(Safety Algorithm)
#include <stdio.h>
int main()
{
    int m,n,i,j,k,y,alloc[20][20],max[20][20],avail[50],ind=0;
    printf("Enter the no. of process and resources:");
    scanf("%d %d",&n,&m);
    printf("Enter the allocation matrix:\n");
    for(i=0;i<n;i++) 
    {
        for(j=0;j<m;j++)
        scanf("%d",&alloc[i][j]);
    }
    printf("Enter the max matrix:\n");
     for(i=0;i<n;i++) 
    {
        for(j=0;j<m;j++)
        scanf("%d",&max[i][j]);
    }
    printf("Enter available matrix\n");
    for(i=0;i<m;i++)
    scanf("%d",&avail[i]);
    int finish[n],safeseq[n],work[m],need[n][m];
    for(i=0;i<m;i++)
    {
        work[i]=avail[i];
    }
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
     for(i=0;i<n;i++) 
    {
        for(j=0;j<m;j++)
        need[i][j]=max[i][j]-alloc[i][j];
    }
    printf("Need matrix is");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
        printf("%d ",need[i][j]);
    }
    for(i=0;i<m;i++)
    {
        work[i]=avail[i];
    }
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                int flag=0;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        flag=1; break;
                    }
                }
                if(flag==0)
                {
                    safeseq[ind++]=i;
                    for(y=0;y<m;y++)
                    work[y]+=alloc[i][y];
                    finish[i]=1;
                }
            }
        }
    }
    printf("\nFollowing is the safe seq\n");
    for(i=0;i<=n-1;i++)
    printf("P%d ",safeseq[i]);
}

/*OUTPUT
Enter the no. of process and resources:5
4
Enter the allocation matrix:
0 0 1 2
1 0 0 0
1 3 5 4
0 6 3 2
0 0 1 4
Enter the max matrix:
0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6
Enter available matrix
1 5 2 0
Need matrix is
0 0 0 0 
0 7 5 0 
1 0 0 2 
0 0 2 0 
0 6 4 2 
Following is the safe seq
P0 P2 P3 P4 P1 */
