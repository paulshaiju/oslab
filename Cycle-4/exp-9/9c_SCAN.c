//Write a C Program to implement the SCAN disk scheduling algorithm. 
#include <stdio.h>
#include <stdlib.h>
int main()
{
int RQ[100],i,in,j,n,TotalHeadMoment=0,initial,size,move;
printf("Enter the  no. of requests\n");
scanf("%d",&n);
printf("Enter the requests seq:");
for(i=0;i<n;i++)
scanf("%d",&RQ[i]);
printf("Enter initial head position:");
scanf("%d",&initial);
in=initial;
printf("Enter total disk size:");
scanf("%d",&size);
printf("Enter the head movement direction for high 1 and for low 0\n");
scanf("%d",&move);
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(RQ[j]>RQ[j+1])
{
int temp;
temp=RQ[j];
RQ[j]=RQ[j+1];
RQ[j+1]=temp;
}
}
}
int index;
for(i=0;i<n;i++)
{
if(initial<RQ[i])
{
index=i;
break;
}
}
if(move==1)
{
for(i=index;i<n;i++)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
initial=RQ[i];
}
TotalHeadMoment=TotalHeadMoment+abs(size-RQ[i-1]-1);
initial=size-1;
for(i=index-1;i>=0;i--)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
initial=RQ[i];
}
}
else
{
for(i=index-1;i>=0;i--)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);

initial=RQ[i];
}
TotalHeadMoment=TotalHeadMoment+abs(RQ[i+1]-0);
initial=0;
for(i=index;i<n;i++)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
initial=RQ[i];
}
}
printf("Total HM is %d",TotalHeadMoment);
printf("\nSequence of Head Movements: ");
printf("%d ", in); // Print initial head position

if (move == 1) {
    for (i = index; i < n; i++) {
        printf("%d ", RQ[i]);
    }
    printf("%d ", size - 1); // Print the end of the disk
    for (i = index - 1; i >= 0; i--) {
        printf("%d ", RQ[i]);
    }
} else {
    for (i = index - 1; i >= 0; i--) {
        printf("%d ", RQ[i]);
    }
    printf("0 "); // Print the beginning of the disk
    for (i = index; i < n; i++) {
        printf("%d ", RQ[i]);
    }
}

printf("\n");

return 0;
}

/*OUTPUT
Enter the  no. of requests
8
Enter the requests seq:98
183
37
122
14
124
65
67
Enter initial head position:53
Enter total disk size:200
Enter the head movement direction for high 1 and for low 0
0
Total HM is 236
Sequence of Head Movements: 53 37 14 0 65 67 98 122 124 183 */