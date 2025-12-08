#include <stdio.h>

int s[10], d, n, set[10], count = 0, flag = 0;

void display();

void subset(int sum, int i)
{
    if (sum == d)
    {
        display();
        flag = 1;
        return;
    }
    if (sum > d || i >= n)
        return;

    set[count++] = s[i];
    subset(sum + s[i], i + 1);
    count--;
    subset(sum, i + 1);
}

void display()
{
    int i;
    printf("{ ");
    for (i = 0; i < count; i++)
        printf("%d ", set[i]);
    printf("}\n");
}

void main()
{
    int i;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &s[i]);

    printf("Enter the sum: ");
    scanf("%d", &d);

    printf("The Program output is:\n");
    subset(0, 0);

    if (flag == 0)
        printf("There is no solution.\n");
}
