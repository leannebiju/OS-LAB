//preemptive priority scheduling

#include<stdio.h>

struct Process
{
    char name[5];
    int at, bt, ct, tat, wt, priority, remaining_bt, completed;
};

void preemptivePriority(struct Process p[], int n)
{
    int currentTime = 0, completed = 0, minPriority;
    int ganttChart[100]; 
    int ganttIndex = 0;   
	float att = 0.0, awt = 0.0; float ttt =0.0, twt = 0.0;

    while (completed < n)
    {
        minPriority = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= currentTime && p[i].remaining_bt > 0)
            {
                if (minPriority == -1 || p[i].priority < p[minPriority].priority)
                    minPriority = i;
            }
        }

        if (minPriority == -1)
        {
            currentTime++;
            continue;
        }

       
        if (ganttIndex == 0 || ganttChart[ganttIndex - 1] != minPriority) {
            ganttChart[ganttIndex++] = minPriority;
        }
        
        p[minPriority].remaining_bt--;
        
        if (p[minPriority].remaining_bt == 0)
        {
            p[minPriority].ct = currentTime + 1;
            p[minPriority].tat = p[minPriority].ct - p[minPriority].at;
            p[minPriority].wt = p[minPriority].tat - p[minPriority].bt;
			twt = twt + p[minPriority].wt;
			ttt = ttt + p[minPriority].tat;
            completed++;
        }

        currentTime++;
    }

    
    printf("\nGantt chart: ");
    for (int i = 0; i < ganttIndex; i++)
        printf("|%s", p[ganttChart[i]].name);
    printf("|\n");
	
	att = ttt/n;
	awt = twt/n;
	
	printf("\nAverage Wait Time : %f", awt);
	printf("\nAverage TurnAround Time : %f\n", att);
}

void display(struct Process p[], int n)
{
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[i].name, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
}

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter process name:\n");
        scanf("%s", p[i].name);
        printf("Enter arrival time, burst time, priority:\n");
        scanf("%d", &p[i].at);
        scanf("%d", &p[i].bt);
        scanf("%d", &p[i].priority);
        p[i].remaining_bt = p[i].bt;
        p[i].completed = 0;
    }

    preemptivePriority(p, n);
    display(p, n);
	

    return 0;
}