// 4.d PROGRAM TO STIMULATE NON-PREEMPTIVE Priority
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct{ 
	int pno;
	int pri;
	int bt;
	int wt;
	} sp;

int main(){ 
	int i,j,n;
	int tbm = 0, totwt = 0,tottat = 0;
	sp *p,t;
	printf("\n Enter the Number of Process : ");
	scanf("%d", &n);
	p = (sp*) malloc (sizeof(sp));
	printf("\nEnter the Burst time and priority : \n");
	for ( i = 0; i < n; i++){
	printf("Process %d : ", i+1); 
	scanf("%d%d", &p[i].bt,&p[i].pri); 
	p[i].pno = i+1;
	p[i].wt=0;
	}

	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++){ 
			if(p[i].pri>p[j].pri){ 
				t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
	printf("\nProcess\tBurst Time\tWaiting Time\tcompletion time\tTurnaround Time\n"); 
	for ( i = 0; i < n; i++){
		totwt += p[i].wt=tbm; 
		tbm += p[i].bt; 
		printf("\n%d\t\t%d",p[i].pno,p[i].bt);
		printf("\t\t%d\t\t%d\t\t%d",p[i].wt,p[i].wt+p[i].bt,p[i].wt+p[i].bt);
	}
	tottat = tbm + totwt;
printf("\nGantt chart:\n");
for(i=0;i<n;i++)
{
    printf("p[%d]_",p[i].pno);
}
	printf("\n Average Waiting time:%f",(float)totwt/n);

	printf("\n Avg Turnaround time:%f",(float)tottat/n);
return 0;
}

/*OUTPUT
 Enter the Number of Process : 3

Enter the Burst time and priority : 
Process 1 : 3
2
Process 2 : 1
1
Process 3 : 2
3

Process Burst Time      Waiting Time    completion time Turnaround Time

2               1               0               1               1
1               3               1               4               4
3               2               4               6               6
Gantt chart:
p[2]_p[1]_p[3]_
 Average Waiting time:1.666667
 Avg Turnaround time:3.666667 */


