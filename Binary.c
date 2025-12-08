#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int binsearch(int a[], int k, int low, int high);
int linsearch(int a[], int n, int k);

int main()
{
    int ch = 1, n, i, a[100], k, op, low, high, pos;
    clock_t begin, end;

    while (ch)
    {
        printf("\n===== MENU =====\n");
        printf("1. Binary Search\n");
        printf("2. Linear Search\n");
        printf("3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nEnter number of elements: ");
            scanf("%d", &n);

            printf("\nEnter array elements (sorted):\n");
            for (i = 0; i < n; i++)
                scanf("%d", &a[i]);

            printf("\nEnter element to search: ");
            scanf("%d", &k);

            low = 0;
            high = n - 1;

            begin = clock();
            pos = binsearch(a, k, low, high);
            end = clock();

            if (pos == -1)
                printf("\nUnsuccessful search\n");
            else
                printf("\nElement %d found at position %d\n", k, pos + 1);

            printf("Time taken: %lf sec\n", (double)(end - begin) / CLOCKS_PER_SEC);
            break;

        case 2:
            printf("\nEnter number of elements: ");
            scanf("%d", &n);

            printf("\nEnter array elements:\n");
            for (i = 0; i < n; i++)
                scanf("%d", &a[i]);

            printf("\nEnter element to search: ");
            scanf("%d", &k);

            begin = clock();
            pos = linsearch(a, n, k);
            end = clock();

            if (pos == -1)
                printf("\nUnsuccessful search\n");
            else
                printf("\nElement %d found at position %d\n", k, pos + 1);

            printf("Time taken: %lf sec\n", (double)(end - begin) / CLOCKS_PER_SEC);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice\n");
        }

        printf("\nDo you want to run again? (1/0): ");
        scanf("%d", &ch);
    }

    return 0;
}

int binsearch(int a[], int k, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;
    sleep(1);

    if (a[mid] == k)
        return mid;
    else if (k < a[mid])
        return binsearch(a, k, low, mid - 1);
    else
        return binsearch(a, k, mid + 1, high);
}

int linsearch(int a[], int n, int k)
{
    sleep(1);

    if (n == 0)
        return -1;

    if (a[n - 1] == k)
        return n - 1;

    return linsearch(a, n - 1, k);
}
