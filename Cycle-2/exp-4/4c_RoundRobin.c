// 4. c) Simulate Round Robin CPU scheduling
#include<stdio.h>
int main()
{
	int n,i,qt,count=0,temp,sq=0,bt[10],wt[10],tat[10],rem_bt[10];
	float awt=0,atat=0;
	printf("Enter number of process: ");
	scanf("%d",&n);
	printf("Enter burst time of process: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
		rem_bt[i]=bt[i];
	}
	printf("Enter quantum time: ");
	scanf("%d",&qt); 
	printf("Gantt chart\n");
	while(1)
	{
		for(i=0,count=0;i<n;i++)
		{
			temp=qt;
			if(rem_bt[i]==0)
			{
				count++;
				continue;
			}
			if(rem_bt[i]>qt)
			   { rem_bt[i]=rem_bt[i]-qt;  printf("p[%d] ",i+1); }
			else
			if(rem_bt[i]>=0)
			{
			     printf("p[%d] ",i+1);
				temp=rem_bt[i];
				rem_bt[i]=0;
			}
			sq=sq+temp;
			tat[i]=sq;
		}
		if(n==count)
		break;
	}
	printf("\nprocess\tburst time\tcompletion time\tturnaround time\twaiting time\n");
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
		awt=awt+wt[i];
		atat=atat+tat[i];
		printf("\n%d\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d",i+1,bt[i],tat[i],tat[i],wt[i]);
	}
	awt=awt/n;
	atat=atat/n;
	printf("\nAverage waiting time=%f\n",awt);
	printf("Average turnaround time=%f",atat);
	
}
/*output
Enter number of process: 3
Enter burst time of process: 3 1 2
Enter quantum time: 1
Gantt chart
p[1] p[2] p[3] p[1] p[3] p[1] 
process	burst time	completion time	turnaround time	waiting time

1		3			6				6				3
2		1			2				2				1
3		2			5				5				3
Average waiting time=2.333333
Average turnaround time=4.333333 */