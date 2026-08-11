#include <stdio.h>

int main() {
    int n, m, i, j, k;

    // Step 2: Input number of processes and resource types
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m];

    // Step 3: Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input Maximum Matrix
    printf("\nEnter Maximum Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Available Vector
    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    // Step 4: Calculate Need Matrix
    printf("\nNeed Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Step 5: Initialize Work and Finish
    int work[m];
    int finish[n];
    int safeSeq[n];

    for(i = 0; i < m; i++)
        work[i] = avail[i];

    for(i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;

    // Step 6: Repeat until all processes are finished
    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {

                // Check if Need <= Work
                for(j = 0; j < m; j++) {
                    if(need[i][j] > work[j])
                        break;
                }

                if(j == m) {
                    // Work = Work + Allocation
                    for(k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    finish[i] = 1;
                    safeSeq[count++] = i;
                    found = 1;
                }
            }
        }

        // Step 7: No suitable process found
        if(found == 0)
            break;
    }

    if(count == n) {
        printf("\nSystem is in SAFE state.\n");
        printf("Safe Sequence: ");

        for(i = 0; i < n; i++) {
            printf("P%d", safeSeq[i]);
            if(i != n - 1)
                printf(" -> ");
        }
        printf("\n");
    } else {
        printf("\nSystem is NOT in SAFE state.\n");
    }

    // Lab information
    printf("\n---------------------------------------\n");
    printf("Lab No.: 4 Name: Karuna Achhami   Roll No.: 46   Section: B\n");
    printf("---------------------------------------\n");


    return 0;
}