#include <stdio.h>

int main() {
    int n, tq, total = 0, x, counter = 0;
    int wt = 0, tat = 0, bt[20], temp[20];
    float avg_wt, avg_tat;

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);
    x = n; // Number of processes remaining   //having a copy of n

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for (int i = 0; i < n; i++) {
        printf("\nP[%d]\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i]; // Store burst times in temp array //having a copy of bt[] array
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; x != 0;) {
        if (temp[i] <= tq && temp[i] > 0) {
            total += temp[i];
            temp[i] = 0;
            counter = 1;
        } else if (temp[i] > 0) {
            temp[i] -= tq;
            total += tq;
        }

        if (temp[i] == 0 && counter == 1) {
            x--;
            printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], total - bt[i], total);
            wt += total - bt[i];
            tat += total;
            counter = 0;
        }

        if (i == n - 1) {
            i = 0;
        } else if (i < n - 1) {
            i++;
        }
    }

    avg_wt = (float)wt / n;
    avg_tat = (float)tat / n;

    printf("\nAverage Waiting Time: %.2f sec", avg_wt);
    printf("\nAverage Turnaround Time: %.2f sec\n", avg_tat);

    return 0;
}
