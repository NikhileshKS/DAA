#include <stdio.h>
#include <unistd.h>
#include <time.h>

void quicksort(int a[10], int low, int high);
int partition(int a[], int low, int high);

void quicksort(int a[10], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = partition(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot, i, j, temp;
    pivot = a[low]; // Choose first element as pivot
    i = low + 1;
    j = high;

    while (i <= j)
    {
        while (i <= high && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Place pivot in its correct position
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j; // Return pivot index
}

int main()
{
    int a[10], n, i;
    int ch = 1;
    clock_t begin, end;
    double time_taken;

    while (ch)
    {
        printf("Enter the size of array: ");
        scanf("%d", &n);

        printf("Enter the elements:\n");
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);

        printf("Unsorted array is:\n");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);

        begin = clock();
        quicksort(a, 0, n - 1);
        end = clock();

        time_taken = ((double)(end - begin)) / CLOCKS_PER_SEC;

        printf("\n\nThe sorted array is:\n");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);

        printf("\nTime taken: %lf seconds\n", time_taken);

        printf("\nDo you wish to run again (1/0)? ");
        scanf("%d", &ch);
    }

    return 0;
}