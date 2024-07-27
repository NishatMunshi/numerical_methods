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
double phi(const unsigned numberOfEntries, const double *x, const double *y, const double w)
{
    double temp = 0, term;
    for (int i = 0; i < numberOfEntries; i++)
    {
        term = dividedDifference(x, y, i, 0);
        for (int j = 0; j < i + 1; j++)
        {
            if (i == j)
                continue;
            else
                term *= (w - x[j]);
        }
        temp += term;
    }
    return temp;
}
void main()
{
    unsigned numberOfEntries;
    printf("How many entries do you have? ");
    scanf("%u", &numberOfEntries);
    double *x = (double *)malloc(numberOfEntries * sizeof(double));
    double *y = (double *)malloc(numberOfEntries * sizeof(double));
    double w; // variable to use finally is w
    printf("\n");
    for (int i = 0; i < numberOfEntries; i++)
    {
        printf("x%d = ", i);
        scanf("%lf", &x[i]);
    }
    printf("\n");
    for (int i = 0; i < numberOfEntries; i++)
    {
        printf("f(x%d) = ", i);
        scanf("%lf", &y[i]);
    }
    printf("\nWhich point to approximate f(x) at? ");
    scanf("%lf", &w);
    printf("\nThe value of f at x = %.2lf is %.2lf\n", w, phi(numberOfEntries, x, y, w));
}