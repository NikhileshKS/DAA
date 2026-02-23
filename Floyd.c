#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int min(int a, int b) { return (a < b) ? a : b; }

int main(void) {
    int n, i, j, k;
    int c[10][10];

    omp_set_num_threads(4); // optional: request 4 threads

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &c[i][j]);

    // Floyd-Warshall (k outer loop)
    for (k = 0; k < n; k++) {
        #pragma omp parallel for private(i, j)
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }

    printf("\nAll Pair Shortest Path:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d\t", c[i][j]);
        printf("\n");
    }

    return 0;
}
