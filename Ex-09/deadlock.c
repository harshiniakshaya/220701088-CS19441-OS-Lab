#include <stdio.h>

int main() {
    int n = 5, m = 3;
    int alloc[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };
    int max[5][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };
    int avail[3] = {3, 3, 2};
    int f[5] = {0}, ans[5], ind = 0;

    int need[5][3];
    int i,j,k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (f[j] == 0) {
                int flag = 0;
                for (k = 0; k < m; k++) {
                    if (need[j][k] > avail[k]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind] = j;
		    ind++;
                    for (k = 0; k < m; k++) {
                        avail[k] += alloc[j][k];
                    }
                    f[j] = 1;
                }
            }
        }
    }

    printf("The SAFE Sequence is\n");
    for (i = 0; i < n - 1; i++) {
        printf(" P%d ->", ans[i]);
    }
    printf(" P%d\n", ans[n - 1]);
    return 0;
}

