#include<stdio.h>
#include<stdbool.h>

struct procs {
	int pid;
	int arrive;
	int burst;
	int complete;
	int turnaround;
	int wait;
	int remain;
	bool finish;
};

int main() {
	int n, q;
	printf("Enter no. of Processes: ");
	scanf("%d", &n);
	struct procs p[n];
	for(int i=0; i<n; i++) {
		p[i].pid=i+1;
		p[i].finish=false;
		printf("\nFor Process %d:", i+1);
		printf("\nArrival Time: ");
		scanf("%d", &p[i].arrive);
		printf("Burst Time: ");
		scanf("%d", &p[i].burst);
		p[i].remain=p[i].burst;
	}
	printf("Enter Quantum Duration: ");
	scanf("%d", &q);
	for(int i;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(p[j].arrive>p[j+1].arrive){
				struct procs temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	int curtime=0,complete=0;
	int min=-1;
	int remproc=n;
	float twt=0.0, ttt=0.0; float awt=0.0, att=0.0;
	printf("\nGantt Chart:\n |");
	while(remproc>0){
		bool found=false;
		for(int i=0;i<n;i++){
			if(p[i].remain>0 && p[i].arrive<=curtime){
				found=true;
				int exetime=(p[i].remain<q)?p[i].remain:q;
				p[i].remain-=exetime;
				curtime+=exetime;
				if(p[i].pid!=min){
					printf("%d |",p[i].pid);
					min=p[i].pid;
				}
				if(p[i].remain==0){
					p[i].complete=curtime;
					p[i].turnaround=p[i].complete-p[i].arrive;
					p[i].wait=p[i].turnaround-p[i].burst;
					twt = twt+p[i].wait;
					ttt = ttt+p[i].turnaround;
					p[i].finish=true;
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
		printf("\n%d\t%d\t%d\t%d\t%d\t\t%d", p[i].pid, p[i].arrive, p[i].wait, p[i].burst, p[i].turnaround, p[i].complete);
	}
	printf("\n");
	
	awt = twt/n;
	att = ttt/n;
	
	printf("\nAverage Wait Time : %f", awt);
	printf("\nAverage TurnAround Time : %f\n", att);
	
	return 0;
}