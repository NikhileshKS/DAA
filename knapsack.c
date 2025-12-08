#include <stdio.h>

int v[20][20];

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int i, j, p[20], w[20], n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter weight and profit of item %d: ", i);
        scanf("%d%d", &w[i], &p[i]);
    }

    printf("Enter max weight of knapsack: ");
    scanf("%d", &capacity);

    // Initialize DP table
    for (i = 0; i <= n; i++)
        v[i][0] = 0;
    for (j = 0; j <= capacity; j++)
        v[0][j] = 0;

    // Fill the DP table
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= capacity; j++)
        {
            if (w[i] <= j)
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
            else
                v[i][j] = v[i - 1][j];
        }
    }

    // Print DP table
    printf("\nThe Table is:\n");
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= capacity; j++)
            printf("%d\t", v[i][j]);
        printf("\n");
    }

    // Print result
    printf("Maximum profit is: %d\n", v[n][capacity]);

    // Print items included
    printf("\nThe most valuable subset is:\n");
    j = capacity;
    for (i = n; i >= 1; i--)
    {
        if (v[i][j] != v[i - 1][j])
        {
            printf("Item %d with weight %d and profit %d\n", i, w[i], p[i]);
            j = j - w[i];
        }
    }

    return 0;
}
