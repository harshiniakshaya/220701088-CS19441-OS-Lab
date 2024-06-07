#include <stdio.h>
#include <string.h>

void firstFit(int blocks[], int m, int procs[], int n) {
    int alloc[n]; // Allocation array
    memset(alloc, -1, sizeof(alloc)); // Initialize with -1 (not allocated)

    // Allocate each process
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= procs[i]) {
                alloc[i] = j; // Allocate this block to the process
                blocks[j] -= procs[i]; // Reduce available memory in this block
                break; // Move to the next process
            }
        }
    }

    // Print allocation result
    printf("\nProc No.\tProc Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d", i + 1, procs[i]);
        if (alloc[i] != -1)
            printf("\t\t%d", alloc[i] + 1);
        else
            printf("\t\tNot Allocated");
        printf("\n");
    }
}

int main() {
    int blocks[] = {100, 500, 200, 300, 600};
    int procs[] = {212, 417, 112, 226};
    int m = sizeof(blocks) / sizeof(blocks[0]);
    int n = sizeof(procs) / sizeof(procs[0]);

    firstFit(blocks, m, procs, n);

    return 0;
}

