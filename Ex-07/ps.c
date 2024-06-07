#include <stdio.h>

int main() {
    int bt[20], p[20], wt[20], pr[20], i, j, n, total = 0, temp;
    float avg_wt, avg_tat;

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time and Priority\n");
    for (i = 0; i < n; i++) {
        printf("\nP[%d]\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        p[i] = i + 1; // Process number
    }

    // Sorting processes based on priority
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[j] < pr[i]) {
                // Swap priority
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process number
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Declare arrays for turnaround time and waiting time
    int tat[n];
    temp = 0;

    // Calculate turnaround time
    for (i = 0; i < n; i++) {
        tat[i] = temp + bt[i];
        temp = tat[i];
    }

    // Calculate waiting time and total waiting time
    int tot_wat = 0;
    int tot_tat=0;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", p[i], bt[i], tat[i]-bt[i], tat[i]);
	tot_tat+=tat[i];
	tot_wat+=tat[i]-bt[i];
    }

    
    printf("\nAverage Waiting Time = %d", tot_wat/n);
    printf("\nAverage Turnaround Time = %d", tot_tat/n);

    return 0;
}

