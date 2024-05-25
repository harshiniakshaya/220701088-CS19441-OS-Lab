#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j;
    printf("How many processes?: ");
    scanf("%d", &n);

    char name[n][20];
    int btime[n];
    for (i = 0; i < n; i++) {
        printf("Enter Name: ");
        scanf("%s", name[i]);
        printf("Enter Burst Time: ");
        scanf("%d", &btime[i]);
    }

    // Sorting processes by burst time (SJF)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (btime[i] > btime[j]) {
                // Swap burst time
                int temp = btime[i];
                btime[i] = btime[j];
                btime[j] = temp;
                
                // Swap names
                char tempName[20];
                strcpy(tempName, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], tempName);
            }
        }
    }

    int ct[n], cta = 0;
    for (i = 0; i < n; i++) {
        cta += btime[i];
        ct[i] = cta;
    }

    int bt = 0;
    int bta = 0;
    printf("Process\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\n", name[i], bt, ct[i]);
        bt += btime[i];
        bta += bt;
    }

    printf("The average waiting time: %d\n", bta / n);

    return 0;
}
