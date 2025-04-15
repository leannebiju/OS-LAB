#include<stdio.h>

struct procs {
	int pid;
	int at;
	int bt;
	int ct;
	int tt;
	int wt;
	int rt;
	int finish;
};

int main() {
	
	int n, q;
	
	printf("Enter no. of Processes: ");
	scanf("%d", &n);
	
	struct procs p[n];
	for(int i=0; i<n; i++) {
		p[i].pid=i+1;
		p[i].finish=0;
		printf("\nFor Process %d:", i+1);
		printf("\nArrival Time: ");
		scanf("%d", &p[i].at);
		printf("Burst Time: ");
		scanf("%d", &p[i].bt);
		p[i].rt=p[i].bt;
	}
	
	printf("Enter Quantum Duration: ");
	scanf("%d", &q);
	
	for(int i;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(p[j].at>p[j+1].at){
				struct procs temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	
	int curtime=0,ct=0;
	int min=-1;
	int remproc=n;
	
	float twt=0.0, ttt=0.0; float awt=0.0, att=0.0;
	
	printf("\nGantt Chart:\n |");
	while(remproc>0){
		int found=0;
		for(int i=0;i<n;i++){
			if(p[i].rt>0 && p[i].at<=curtime){
				found=1;
				int exetime=(p[i].rt<q)?p[i].rt:q;
				p[i].rt-=exetime;
				curtime+=exetime;
				if(p[i].pid!=min){
					printf("%d |",p[i].pid);
					min=p[i].pid;
				}
				if(p[i].rt==0){
					p[i].ct=curtime;
					p[i].tt=p[i].ct-p[i].at;
					p[i].wt=p[i].tt-p[i].bt;
					twt = twt+p[i].wt;
					ttt = ttt+p[i].tt;
					p[i].finish=1;
					remproc--;
				}
			}
		}
		if(!found){
			curtime++;
		}
	}
	printf("\n");
	printf("\nProcess\tArrival\tWaiting\tBurst\tTurnaround\tCompletion");
	for(int i=0; i<n; i++) {
		printf("\n%d\t%d\t%d\t%d\t%d\t\t%d", p[i].pid, p[i].at, p[i].wt, p[i].bt, p[i].tt, p[i].ct);
	}
	printf("\n");
	
	awt = twt/n;
	att = ttt/n;
	
	printf("\nAverage Wait Time : %f", awt);
	printf("\nAverage TurnAround Time : %f\n", att);
	
	return 0;
}