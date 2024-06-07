#include <stdio.h>
#include <string.h>

void bestFit(int blocks[], int m, int procs[], int n) {
    int alloc[n]; // Allocation array
    memset(alloc, -1, sizeof(alloc)); // Initialize with -1 (not allocated)

    // Allocate each process
    for (int i = 0; i < n; i++) {
        int best = -1; // Index of the best block

        for (int j = 0; j < m; j++) {
            if (blocks[j] >= procs[i]) {
                if (best == -1 || blocks[j] < blocks[best]) {
                    best = j;
                }
            }
        }

        // If a suitable block is found
        if (best != -1) {
            alloc[i] = best; // Allocate this block to the process
            blocks[best] -= procs[i]; // Reduce available memory in this block
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
    int procs[] = {212, 417, 112, 426};
    int m = sizeof(blocks) / sizeof(blocks[0]);
    int n = sizeof(procs) / sizeof(procs[0]);

    bestFit(blocks, m, procs, n);

    return 0;
}

