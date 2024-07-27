#include <stdio.h>
#include <stdlib.h>
double dividedDifference(const double *x, const double *y, const unsigned order, const unsigned subs0)
{
    if (order == 0)
    {
        return y[subs0];
    }
    else
    {
        return (dividedDifference(x, y, order - 1, subs0) - dividedDifference(x, y, order - 1, subs0 + 1)) / (x[subs0] - x[subs0 + order]);
    }
}
void printTable(const unsigned noe, const double *x, const double *y)
{
    printf("\n");
    for (unsigned i = 0; i < noe; i++)
    {
        printf("%lf\t", x[i]);
        for (unsigned j = 0; j < noe; j++)
        {
            if (j > noe - i - 1)
                continue;
            printf("%lf\t", dividedDifference(x, y, j, i));
        }
        printf("\n");
    }
}
void main()
{
    unsigned noe;
    printf("How many entries do you have? ");
    scanf("%u", &noe);
    double *x = (double *)malloc(noe * sizeof(double));
    double *y = (double *)malloc(noe * sizeof(double));
    double w; // variable to use finally is w
    printf("\n");
    for (int i = 0; i < noe; i++)
    {
        printf("x%d = ", i);
        scanf("%lf", &x[i]);
    }
    printf("\n");
    for (int i = 0; i < noe; i++)
    {
        printf("f(x%d) = ", i);
        scanf("%lf", &y[i]);
    }
    printTable(noe, x, y);
}