#include <stdio.h>

int a[10][10];

int main()
{
    int i, j, k, n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Make diagonal = 1 (reflexive closure)
    for (i = 0; i < n; i++)
        a[i][i] = 1;

    // Warshall’s algorithm
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
            }
        }
    }

    printf("Transitive closure matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
