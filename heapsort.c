#include <stdio.h>
#include <time.h> // for clock()

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // Extract elements
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}

int main()
{
    int arr[50];
    int n;

    clock_t begin, end;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements in array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nThe unsorted array is:\n");
    printarray(arr, n);

    begin = clock();
    heapsort(arr, n);
    end = clock();

    printf("\nThe sorted array is:\n");
    printarray(arr, n);

    double time_taken = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}