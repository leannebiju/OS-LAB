#include <stdio.h>

struct process {
    int id;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
    int remaining;
};

// Function for Round Robin Scheduling
void RoundRobin(struct process p[], int n, int quantum) {
    int time = 0, completed = 0;
    int totalwaiting = 0, totalturnaround = 0;
    int queue[100], front = 0, rear = 0; // Queue for RR execution
    int gantt[100], gantt_time[100], g_index = 0; // Gantt Chart Storage
    int visited[n];

    // Initialize remaining burst time and visited array
    for (int i = 0; i < n; i++) {
        p[i].remaining = p[i].burst;
        visited[i] = 0; // Mark all processes as not visited
    }

    // Find the first process to start
    int min_arrival = 9999, first_process = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].arrival < min_arrival) {
            min_arrival = p[i].arrival;
            first_process = i;
        }
    }

    time = p[first_process].arrival; // Start at the first arrival
    queue[rear++] = first_process; // Add first process to the queue
    visited[first_process] = 1;

    while (completed < n) {
        int process_index = queue[front++];
        
        // Add process to Gantt Chart
        gantt[g_index] = process_index;
        gantt_time[g_index++] = time;

        // Process execution
        if (p[process_index].remaining > quantum) {
            time += quantum;
            p[process_index].remaining -= quantum;
        } else {
            time += p[process_index].remaining;
            p[process_index].remaining = 0;
            p[process_index].completion = time;
            p[process_index].turnaround = p[process_index].completion - p[process_index].arrival;
            p[process_index].waiting = p[process_index].turnaround - p[process_index].burst;
            totalwaiting += p[process_index].waiting;
            totalturnaround += p[process_index].turnaround;
            completed++;
        }

        // Enqueue newly arrived processes
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        // Re-enqueue unfinished process
        if (p[process_index].remaining > 0) {
            queue[rear++] = process_index;
        }

        // If queue is empty, find the next process to start
        if (front == rear && completed < n) {
            for (int i = 0; i < n; i++) {
                if (p[i].remaining > 0) {
                    queue[rear++] = i;
                    visited[i] = 1;
                    time = p[i].arrival; // Jump time to next available process
                    break;
                }
            }
        }
    }

    // Print Gantt Chart
    printf("\nGantt Chart\n");
    for (int i = 0; i < g_index; i++) {
        printf("| P%d ", p[gantt[i]].id);
    }
    printf("|\n");

    printf(" ");
    for (int i = 0; i < g_index; i++) {
        printf(" %d  ", gantt_time[i]);
    }
    printf("%d\n", time);

    // Print process details
    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].arrival, p[i].burst, p[i].completion, p[i].turnaround, p[i].waiting);
    }

    // Print averages
    printf("Average Waiting Time: %.2f", (float)totalwaiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalturnaround / n);
}

int main() {
    int n, quantum;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    struct process p[n];
    
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time and burst time for process %d: \n", i + 1);
        scanf("%d%d", &p[i].arrival, &p[i].burst);
    }
    
    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);
    
    RoundRobin(p, n, quantum);
    
    return 0;
}
