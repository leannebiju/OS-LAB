#include <stdio.h>

// Function to display Gantt Chart
void drawGanttChart(int processes[], int n, int burstTime[]) {
    int completionTime[n];
    int startTime = 0;
    
    printf("\nGantt Chart:\n");
    printf(" ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < burstTime[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < burstTime[i] - 1; j++) printf(" ");
        printf("P%d", processes[i]);
        for (int j = 0; j < burstTime[i] - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < burstTime[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n0");
    
    for (int i = 0; i < n; i++) {
        startTime += burstTime[i];
        printf("%*d", burstTime[i] + 1, startTime);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int processes[n], burstTime[n];
    
    printf("Enter process numbers and burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i], &burstTime[i]);
    }
    
    drawGanttChart(processes, n, burstTime);
    
    return 0;
}
