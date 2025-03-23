//shortest job first - non-preemptive

#include<stdio.h>

struct process{
	int id;
	int arrival;
	int burst;
	int completion;
	int turnaround;
	int waiting;
	int remaining;
};

void SJF(struct process p[], int n){
	int totalwaiting = 0, totalturnaround = 0;
	int finished = 0, time = 0, minIndex, minBurst;
	int store[n];
	int k = 0;
	
	for(int i = 0; i<n-1; i++){
		for(int j = i+1; j<n; j++){
			if(p[i].arrival > p[j].arrival){
				struct process temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	
	for(int i =0; i<n; i++){
		p[i].remaining = p[i].burst;
	}
	
	while(finished<n){
		minIndex = -1;
		minBurst = 9999;
		for(int i = 0; i<n; i++){
			if(p[i].arrival<=time && p[i].remaining>0 && p[i].remaining<minBurst){
				minBurst = p[i].remaining;
				minIndex = i;
			}
		}
		if(minIndex == -1){
			time++;
			continue;
		}
		store[k++]=minIndex;
		p[minIndex].remaining = p[minIndex].burst;
		time+=p[minIndex].remaining;
		p[minIndex].completion = time;
		p[minIndex].turnaround = p[minIndex].completion - p[minIndex].arrival;
		p[minIndex].waiting = p[minIndex].turnaround - p[minIndex].burst;
		p[minIndex].remaining = 0;
		finished++;
	}
	
	printf("\nGantt Chart\n");
	for(int i = 0; i<n; i++){
		printf("| P%d ", p[store[i]].id);
	}
	printf("|\n");
	
	printf(" ");
	for(int i = 0; i<n; i++){
		printf("  %d ", p[store[i]].completion);
	}
	printf("\n");
	
	printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
	for(int i = 0; i<n; i++){
		totalwaiting+=p[store[i]].waiting;
		totalturnaround+=p[store[i]].turnaround;
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[store[i]].id, p[store[i]].arrival, p[store[i]].burst, p[store[i]].completion, p[store[i]].turnaround, p[store[i]].waiting);
	}
	
	printf("Average waiting Time : %.2f", (float)totalwaiting/n);
	printf("\nAverage turnaround Time : %.2f", (float)totalturnaround/n);
}

int main(){
	int n;
	printf("Enter number of processes : ");
	scanf("%d", &n);
	struct process p[n];
	
	for(int i = 0; i<n; i++){
		p[i].id = i+1;
		printf("Enter arrival time and burst time for the proccess %d: \n", i+1);
		scanf("%d%d", &p[i].arrival, &p[i].burst);
	}
	
	SJF(p,n);
	return 0;
}