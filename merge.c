#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

/* Function declarations */
void mergesort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

int main()
{
    int n, i, ch = 1;
    int a[100];
    clock_t start, end;

    while (ch)
    {
        printf("Enter number of elements: ");
        scanf("%d", &n);

        printf("Enter elements:\n");
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);

        printf("Unsorted array:\n");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        start = clock();
        mergesort(a, 0, n - 1);
        end = clock();

        printf("Sorted array:\n");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        printf("Time taken: %lf seconds\n",
               (double)(end - start) / CLOCKS_PER_SEC);

        printf("Run again? (1=yes, 0=no): ");
        scanf("%d", &ch);
    }

    return 0;
}

/* Merge Sort using OpenMP */
void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            mergesort(a, low, mid);

            #pragma omp section
            mergesort(a, mid + 1, high);
        }

        merge(a, low, mid, high);
    }
}

/* Merge function */
void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int temp[100];

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = temp[i];
}
