//FCFS scheduling with accounting for CPU idle time 

#include<stdio.h>

struct process{
	int pid;
	int at;
	int bt;
	int ct;
	int wt;
	int tt;
};

int main(){
	
	int n;
	
	printf("Enter the number of processes: \n");
	scanf("%d", &n);
	
	struct process pro[n];
	for(int i = 0; i<n; i++){
		pro[i].pid = i+1;
		printf("\nProcess %d", (i+1));
		printf("\nArrival Time : ");
		scanf("%d", &pro[i].at);
		printf("Burst Time : ");
		scanf("%d", &pro[i].bt);
	}
	
	struct process temp;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n-i-1; j++){
			if(pro[j].at>pro[j+1].at){
				temp = pro[j];
				pro[j] = pro[j+1];
				pro[j+1] = temp;
			}
		}
	}

	int currtime = 0;
	float awt, att, ttt = 0.0, twt = 0.0;
	
	for(int i = 0; i<n; i++){
		
		if(currtime<pro[i].at)
			currtime = pro[i].at;
		
		pro[i].ct = currtime + pro[i].bt;
		pro[i].tt = pro[i].ct - pro[i].at;
		pro[i].wt = pro[i].tt - pro[i].bt;
		
		currtime = pro[i].ct;
		
		ttt = ttt + pro[i].tt;
		twt = twt + pro[i].wt;
	}
	
	
	
	printf("\nPID\t\tAT\t\tBT\t\tWT\t\tTT\t\tCT");
	for(int i = 0; i<n; i++){
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", pro[i].pid, pro[i].at, pro[i].bt, pro[i].wt, pro[i].tt, pro[i].ct);	
	}
	
	awt = twt/n;
	att = ttt/n;
	printf("\nAverage Wait Time : %f", awt);
	printf("\nAverage TurnAround Time : %f", att);
}