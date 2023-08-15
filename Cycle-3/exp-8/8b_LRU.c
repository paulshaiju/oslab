//LRU PROGRAM
#include<stdio.h>
void main()
{
    int i,j,k,min,rs[25],m[10],count[10],flag[25],n,f,pf=0,next=0;
    printf("Enter the length of the reference string --");
    scanf("%d",&n);
    printf("Enter the reference string -- ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
        flag[i]=0;
    }
    printf("Enter the number of frames -- ");
    scanf("%d",&f);
    for(i=0;i<f;i++)
    {
        count[i]=0;
        m[i]=-1;
    }
printf("\nThe Page Replacement process is -- \n");
for(i=0;i<n;i++)
{
    for(j=0;j<f;j++)
    {
        if(m[j]==rs[i])
        {
            flag[i]=1;
            count[j]=next;
            next++;
        }
    }
    if(flag[i]==0)
    {
        if(i<f)
        {
            m[i]=rs[i];
            count[i]=next;
            next++;
        }
        else
        {
            min=0;
            for(j=0;j<f;j++)
            if(count[min] > count[j])
                min=j;
            m[min]=rs[i];
            count[min]=next;
            next++;
        }
        pf++;
    }
    for(j=0;j<f;j++)
    printf("%d\t",m[j]);
    if(flag[i]==0)
    printf("PF no. -- %d",pf);
    printf("\n");
}
printf("\nThe number of page faults using LRU are %d",pf);
printf("\nThe number of page hits using LRU are %d",n-pf);
}

/*OUTPUT
Enter the length of the reference string --12
Enter the reference string -- 2 3 2 1 5 2 4 5 3 2 5 2
Enter the number of frames -- 3

The Page Replacement process is -- 
2       -1      -1      PF no. -- 1
2       3       -1      PF no. -- 2
2       3       -1
2       3       1       PF no. -- 3
2       5       1       PF no. -- 4
2       5       1
2       5       4       PF no. -- 5
2       5       4
3       5       4       PF no. -- 6
3       5       2       PF no. -- 7
3       5       2
3       5       2

The number of page faults using LRU are 7
The number of page hits using LRU are 5 */