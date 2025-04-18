//non - preemptive shortest job first

#include<stdio.h>

struct process{
	int pid;
	int at;
	int bt;
	int ct;
	int wt;
	int tt;
	int flag;
};

struct gantt{
	int pid;
	int start;
	int end;
};

int main(){
	
	int n;
	
	printf("Enter the number of processes: \n");
	scanf("%d", &n);
	
	struct process pro[n];
	struct gantt gc[n+15];
	int gi = 0;
	
	for(int i = 0; i<n; i++){
		pro[i].pid = i+1;
		pro[i].flag = 0;
		printf("\nProcess %d", (i+1));
		printf("\nArrival Time : ");
		scanf("%d", &pro[i].at);
		printf("Burst Time : ");
		scanf("%d", &pro[i].bt);
	}
	
	int currtime = 0, complete = 0;
	float awt, att, ttt = 0.0, twt = 0.0;
	int mi, mb;
	
	while(complete<n){
		mi = -1;
		mb = 9999;
		
		for(int i = 0; i<n; i++){
			if(pro[i].flag == 0 && pro[i].at<=currtime){
				if(pro[i].bt<mb){
					mb = pro[i].bt;
					mi = i;
				}
			}
		}
	
		if(mi==-1){
			gc[gi].pid = -1;
			gc[gi].start = currtime;
			currtime++;
			gc[gi].end = currtime;
			gi++;
		}
		else{
			gc[gi].pid = pro[mi].pid;
			gc[gi].start = currtime;
			
			pro[mi].ct = currtime + pro[mi].bt;
			pro[mi].tt = pro[mi].ct - pro[mi].at;
			pro[mi].wt = pro[mi].tt - pro[mi].bt;
		
			currtime = pro[mi].ct;
			
			complete++;
			pro[mi].flag = 1;
		
			gc[gi].end = currtime;
			gi++;
		
			ttt = ttt + pro[mi].tt;
			twt = twt + pro[mi].wt;
		}	
	}
	
	printf("\n");
	
	//Gantt chart
	
	for(int i = 0; i<gi; i++){
		printf("|");
		if(gc[i].pid == -1)
			printf(" idle ");
		else 
			printf(" P%d ", gc[i].pid);
	}
	printf("|\n");

	printf("%d", gc[0].start);
	for(int i = 0; i<gi; i++){
		printf("   %d", gc[i].end);
	}
	printf("\n");
	
	
	//Table
	
	printf("\nPID\t\tAT\t\tBT\t\tWT\t\tTT\t\tCT");
	for(int i = 0; i<n; i++){
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", pro[i].pid, pro[i].at, pro[i].bt, pro[i].wt, pro[i].tt, pro[i].ct);	
	}
	
	awt = twt/n;
	att = ttt/n;
	printf("\nAverage Wait Time : %f", awt);
	printf("\nAverage TurnAround Time : %f\n", att);
}