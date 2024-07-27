#include <stdio.h>
#include <stdlib.h>
double phi(const unsigned numberOfEntries, double const *x, double const *y, const double w) // numberOfEntries is number of entries
{
    double lix, result = 0; // temp variable to return f // lix is temp variable to store li(x). we initialize it by 1 in each iteration
    for (int i = 0; i < numberOfEntries; i++)
    {
        lix = 1;
        for (int j = 0; j < numberOfEntries; j++)
        {
            if (i == j)
                continue;
            else
                lix *= (w - x[j]) / (x[i] - x[j]);
        }
        result += y[i] * lix;
    }
    return result;
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