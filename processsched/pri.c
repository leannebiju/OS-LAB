#include <stdio.h>

struct process {
    int id;
    int arrival;
    int burst;
    int remaining;
    int priority;
    int completion;
    int turnaround;
    int waiting;
};

void PriorityScheduling(struct process p[], int n) {
    int time = 0, completed = 0, minPriority, minIndex;
    int totalWaiting = 0, totalTurnaround = 0;
    
    // Gantt chart tracking
    int lastExecuted = -1;
    printf("\nGantt Chart:\n ");
    
    // Time tracking for Gantt Chart
    int ganttTime[100], ganttProcess[100], ganttSize = 0;

    // Sort processes based on arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrival > p[j].arrival) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Initialize remaining time
    for (int i = 0; i < n; i++) {
        p[i].remaining = p[i].burst;
    }

    while (completed < n) {
        minPriority = 9999;
        minIndex = -1;

        // Find process with the highest priority (smallest number) that is ready
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0 && p[i].priority < minPriority) {
                minPriority = p[i].priority;
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            // If no process is ready, CPU is idle
            if (lastExecuted != -2) {
                printf("| Idle ");
                lastExecuted = -2;
                ganttProcess[ganttSize] = -1; // Idle state
                ganttTime[ganttSize++] = time;
            }
            time++;
            continue;
        }

        if (lastExecuted != minIndex) {
            printf("| P%d ", p[minIndex].id);
            lastExecuted = minIndex;
            ganttProcess[ganttSize] = p[minIndex].id;
            ganttTime[ganttSize++] = time;
        }

        p[minIndex].remaining--;

        if (p[minIndex].remaining == 0) {
            // Process finished execution
            p[minIndex].completion = time + 1;
            p[minIndex].turnaround = p[minIndex].completion - p[minIndex].arrival;
            p[minIndex].waiting = p[minIndex].turnaround - p[minIndex].burst;
            totalWaiting += p[minIndex].waiting;
            totalTurnaround += p[minIndex].turnaround;
            completed++;
        }

        time++;
    }
    
    printf("|\n ");

    // Print time labels for Gantt Chart
    for (int i = 0; i < ganttSize; i++) {
        printf("%d   ", ganttTime[i]);
    }
    printf("%d\n", time); // Last time value

    // Print Process Table
    printf("\nProcess ID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
            p[i].id, p[i].arrival, p[i].burst, p[i].priority, 
            p[i].completion, p[i].turnaround, p[i].waiting);
    }

    // Print averages
    printf("Average Waiting Time: %.2f", (float)totalWaiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTurnaround / n);
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time, burst time, and priority for process %d: ", i + 1);
        scanf("%d%d%d", &p[i].arrival, &p[i].burst, &p[i].priority);
    }

    PriorityScheduling(p, n);

    return 0;
}
