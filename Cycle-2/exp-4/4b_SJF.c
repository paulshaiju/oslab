//4. b) Simulate SJF(non-preemptive) CPU scheduling 
#include<stdio.h>
int main() {
	int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp; 
	float avg_wt, avg_tat;
	printf("Enter number of process:");
	scanf("%d",&n);

	printf("\n Enter Burst Time:\n");
	for( i = 0; i < n; i++){
		printf("p%d:",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	for( i = 0; i < n; i++){ 
		pos = i;
		for( j = i+1; j < n; j++){
			if( bt[j] < bt[pos])
				pos = j;
		}
	temp = bt[i];
	bt[i] = bt[pos];
	bt[pos] = temp;
	temp = p[i];
	p[i] = p[pos];
	p[pos] = temp;
	}
	wt[0] = 0;
	for( i = 1; i < n; i++){ 
		wt[i] = 0;
		for( j = 0; j < i; j++)
			{
				wt[i] += bt[j];
			}
			total += wt[i];
	}
	avg_wt = (float)total / n;
	total = 0;
printf("Gantt Chart:\n");
for(int k=0;k<n;k++)
{
printf("p[%d]_",p[k]); }
	printf("\nProcess\tBurst Time\tcompletion time\tWaiting Time\tTurnaround Time");
	for( i = 0; i < n; i++){ 
		tat[i] = bt[i] + wt[i];
		total += tat[i];
		printf("\n p%d\t\t\t %d\t\t\t%d\t\t\t \t%d\t\t\t\t%d",p[i],bt[i],tat[i],wt[i],tat[i]);
	}
	avg_tat = (float)total / n;
	printf("\n\nAverage Waiting Time=%f",avg_wt); printf("\nAverage TurnaroundTime=%f\n",avg_tat);
}
/*OUTPUT
Enter number of process:4

 Enter Burst Time:
p1:1
p2:9
p3:4
p4:6
Gantt Chart:
p[1]_p[3]_p[4]_p[2]_
Process Burst Time      completion time Waiting Time    Turnaround Time
 p1                      1                      1                               0                               1
 p3                      4                      5                               1                               5
 p4                      6                      11                              5                               11
 p2                      9                      20                              11                              20

Average Waiting Time=4.250000
Average TurnaroundTime=9.250000 */
