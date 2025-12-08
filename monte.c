#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n, i;
    double x, y, d, pi;
    double circle_points = 0, square_points = 0;
    printf("Enter number of intervals:");
    scanf("%d", &n);
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        d = x * x + y * y;
        if (d <= 1)
        {
            circle_points++;
        }
        square_points++;
    }
    pi = 4 * circle_points / square_points;
    printf("Estimated value is=%f\n", pi);
    return 0;
}