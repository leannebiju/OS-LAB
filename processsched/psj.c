/* //preemptive sjf

#include <stdio.h>
#include <limits.h>

struct process {
    int id;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
};

// Function to find the process with the shortest remaining time
int findShortestJob(struct process p[], int n, int current_time) {
    int min_index = -1;
    int min_remaining = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (p[i].arrival <= current_time && p[i].remaining > 0 && p[i].remaining < min_remaining) {
            min_remaining = p[i].remaining;
            min_index = i;
        }
    }
    return min_index;
}

// Preemptive SJF Scheduling (SRTF)
void SRTF(struct process p[], int n) {
    int completed = 0, current_time = 0;
    int total_waiting = 0, total_turnaround = 0;
    
    for (int i = 0; i < n; i++)
        p[i].remaining = p[i].burst;  // Initialize remaining burst time

    while (completed < n) {
        int min_index = findShortestJob(p, n, current_time);

        if (min_index == -1) {  
            current_time++;  // No process available, increment time
            continue;
        }

        // Execute process for 1 unit time
        p[min_index].remaining--;
        current_time++;

        // If process completes
        if (p[min_index].remaining == 0) {
            completed++;
            p[min_index].completion = current_time;
            p[min_index].turnaround = p[min_index].completion - p[min_index].arrival;
            p[min_index].waiting = p[min_index].turnaround - p[min_index].burst;

            total_waiting += p[min_index].waiting;
            total_turnaround += p[min_index].turnaround;
        }
    }

    // Print Results
    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].arrival, p[i].burst,
               p[i].completion, p[i].turnaround, p[i].waiting);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_waiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
    }

    SRTF(p, n);
    return 0;
}
 */
 
 #include <stdio.h>
#include <limits.h>

struct process {
    int id;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
};

// Function to find the process with the shortest remaining time
int findShortestJob(struct process p[], int n, int current_time) {
    int min_index = -1;
    int min_remaining = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (p[i].arrival <= current_time && p[i].remaining > 0 && p[i].remaining < min_remaining) {
            min_remaining = p[i].remaining;
            min_index = i;
        }
    }
    return min_index;
}

// Preemptive SJF Scheduling (SRTF)
void SRTF(struct process p[], int n) {
    int completed = 0, current_time = 0;
    int total_waiting = 0, total_turnaround = 0;

    int gantt[100], gantt_time[100], g_index = 0; // Store execution order for Gantt Chart

    for (int i = 0; i < n; i++)
        p[i].remaining = p[i].burst;  // Initialize remaining burst time

    while (completed < n) {
        int min_index = findShortestJob(p, n, current_time);

        if (min_index == -1) {  
            current_time++;  
            continue;
        }

        // Store execution order for Gantt Chart
        gantt[g_index] = p[min_index].id;
        gantt_time[g_index++] = current_time;

        // Execute process for 1 unit time
        p[min_index].remaining--;
        current_time++;

        // If process completes
        if (p[min_index].remaining == 0) {
            completed++;
            p[min_index].completion = current_time;
            p[min_index].turnaround = p[min_index].completion - p[min_index].arrival;
            p[min_index].waiting = p[min_index].turnaround - p[min_index].burst;

            total_waiting += p[min_index].waiting;
            total_turnaround += p[min_index].turnaround;
        }
    }

    // Print Gantt Chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < g_index; i++) {
        if (i == 0 || gantt[i] != gantt[i - 1]) {  // Print process switch
            printf("| P%d ", gantt[i]);
        }
    }
    printf("|\n");

    for (int i = 0; i < g_index; i++) {
        if (i == 0 || gantt[i] != gantt[i - 1]) {  // Print time switch
            printf("%d   ", gantt_time[i]);
        }
    }
    printf("%d\n", current_time);

    // Print Process Table
    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].arrival, p[i].burst,
               p[i].completion, p[i].turnaround, p[i].waiting);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_waiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
    }

    SRTF(p, n);
    return 0;
}