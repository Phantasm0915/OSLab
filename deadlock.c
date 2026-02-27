#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int alloc[10][10], max[10][10];
    int avail[10], work[10], total[10];
    int need[10][10];
    int i, j, k, n, m;
    int count = 0, c = 0;
    char finish[10];

    printf("Enter the number of processes and resources: ");
    if (scanf("%d%d", &n, &m) != 2) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }
    if (n > 10 || m > 10) {
        fprintf(stderr, "Maximum of 10 processes/resources supported\n");
        return 1;
    }

    for (i = 0; i < n; i++)
        finish[i] = 'n';

    printf("Enter the claim matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Resource vector:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &total[i]);

    /* compute available resources */
    for (i = 0; i < m; i++)
        avail[i] = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            avail[j] += alloc[i][j];
    for (j = 0; j < m; j++)
        work[j] = total[j] - avail[j];

    /* compute need matrix */
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    /* safety algorithm */
    do {
        int progressed = 0;

        for (i = 0; i < n; i++) {
            if (finish[i] == 'n') {
                c = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] <= work[j])
                        c++;
                }
                if (c == m) {
                    printf("All the resources can be allocated to Process %d\n", i + 1);
                    printf("\nAvailable resources are:");
                    for (k = 0; k < m; k++) {
                        work[k] += alloc[i][k];
                        printf(" %d", work[k]);
                    }
                    printf("\n");
                    finish[i] = 'y';
                    printf("Process %d executed?: %c\n", i + 1, finish[i]);
                    count++;
                    progressed = 1;
                }
            }
        }
        if (!progressed)
            break;
    } while (count != n);

    if (count == n) {
        printf("\nSystem is in safe mode\n");
        printf("The given state is a safe state\n");
    } else {
        printf("\nSystem is NOT in a safe state\n");
    }

    return 0;
}
