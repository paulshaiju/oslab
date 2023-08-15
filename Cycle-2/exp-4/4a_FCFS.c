//4. a) Simulate FCFS CPU scheduling
#include<stdio.h>
int main(){
	int n, bt[20], wt[20], tat[20], i, j; float avwt = 0, avtat = 0;
	printf("Enter Total Number of processes (max 20) : ");
	scanf("%d",&n);
	printf("\n Enter Process Burst Time \n"); 
	for( i = 0; i < n; i++){ 
		printf("P[%d] : ",i+1);
		scanf("%d" , &bt[i]);
	}
	wt[0] = 0;
	for( i = 1; i < n ; i++){ 
		wt[i] = 0;
		for ( j = 0; j < i; j++)
			wt[i] += bt[j];
		}
		printf("Gantt chart:\n");
		for(int k=1;k<=n;k++)
		{
		    printf("p[%d]__",k);
		}
	printf("\n Process \tBurst Time\tcomp time\tWaiting Time\tTurnaround Time");
	for( i = 0; i < n; i++){
		tat[i] = bt[i] + wt[i];
		avwt += wt[i];
		avtat += tat[i];
		printf("\n P[%d] \t\t\t %d \t\t\t %d\t\t\t%d \t\t\t %d",i+1,bt[i],tat[i],wt[i],tat[i]);
	}
	avwt /= i;
	avtat /= i;
printf("\n\n Average Waiting Time:%f",avwt); printf("\n Average Turnaround Time:%f \n",avtat);
return 0;
}
/*OUTPUT
Enter Total Number of processes (max 20) : 4

 Enter Process Burst Time
P[1] : 3
P[2] : 4
P[3] : 2
P[4] : 1
Gantt chart:
p[1]__p[2]__p[3]__p[4]__
 Process        Burst Time      comp time       Waiting Time    Turnaround Time
 P[1]                    3                       3                      0                        3
 P[2]                    4                       7                      3                        7
 P[3]                    2                       9                      7                        9
 P[4]                    1                       10                     9                        10

 Average Waiting Time:4.750000
 Average Turnaround Time:7.250000 */
