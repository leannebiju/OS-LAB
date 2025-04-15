//preemptive pri scheduling

#include<stdio.h>

struct pro{
    int pid;
    int at;
    int bt;
    int ct;
    int tt;
    int wt;
    int pri;
    int rt;
    int completed;
};

void preemptivePriority(struct pro p[], int n){
	
    int currentTime = 0, completed = 0, mp;
    int gc[100]; 
    int gi = 0;   
    float att = 0.0, awt = 0.0; 
    float ttt =0.0, twt = 0.0;

    while (completed < n){
		
        mp = -1;
        
	for (int i = 0; i < n; i++){
            if (p[i].at <= currentTime && p[i].rt > 0){
                if (mp == -1 || p[i].pri < p[mp].pri)
                    mp = i;
            }
        }

        if (mp == -1){
            currentTime++;
            continue;
        }

        if (gi == 0 || gc[gi - 1] != mp){
            gc[gi++] = mp;
        }
        
        p[mp].rt--;
        
        if (p[mp].rt == 0){
            p[mp].ct = currentTime + 1;
            p[mp].tt = p[mp].ct - p[mp].at;
            p[mp].wt = p[mp].tt - p[mp].bt;
      	    twt = twt + p[mp].wt;
	    ttt = ttt + p[mp].tt;
            completed++;
        }
        currentTime++;
    }

    
    printf("\nGantt chart: ");
    for (int i = 0; i < gi; i++)
        printf("|P%d", p[gc[i]].pid);
    
    printf("|\n");
	
    att = ttt/n;
    awt = twt/n;
	
    printf("\nAverage Wait Time : %f", awt);
    printf("\nAverage TurnAround Time : %f\n", att);
}

void display(struct pro p[], int n){
    printf("\nProcess\tAT\tBT\tPri\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].pri, p[i].ct, p[i].tt, p[i].wt);
}

int main(){

    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    struct pro p[n];
    
    for (int i = 0; i < n; i++){
	p[i].pid = i+1;
	printf("\nProcess %d", i+1);
        printf("\nEnter arrival time :");
        scanf("%d", &p[i].at);
	printf("Enter burst time :");
        scanf("%d", &p[i].bt);
	printf("Enter priority :");
        scanf("%d", &p[i].pri);
        p[i].rt = p[i].bt;
        p[i].completed = 0;
    }

    preemptivePriority(p, n);
    display(p, n);

    return 0;
}
