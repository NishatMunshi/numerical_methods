#include <stdio.h>
#include <stdlib.h>
void takeInput(const unsigned numberOfEntries, double *x, double *y) // takes first two x inputs and fills the rest of x's.
{
    for (int i = 0; i < 2; i++)
    {
        printf("x%d = ", i);
        scanf("%lf", &x[i]);
    }
    for (int i = 0; i < numberOfEntries; i++)
    {
        printf("f(x%d) = ", i);
        scanf("%lf", &y[i]);
    }
    for (int i = 2; i < numberOfEntries; i++)
    {
        x[i] = x[i - 1] + x[1] - x[0];
    }
}
int fact(const int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
    {
        int temp = 1;
        for (int i = n; i > 0; i--)
        {
            temp *= i;
        }
        return temp;
    }
}
double backwardCoeff(const double s, const int r)
{
    double temp = 1;
    for (int i = 0; i < r; i++)
    {
        temp *= (s + i);
    }
    temp = temp / fact(r);
    return temp;
}
double backwardDel(const int order, const int subscript, double const *y)
{
    if (order == 0)
        return y[subscript];
    else
        return backwardDel(order - 1, subscript, y) - backwardDel(order - 1, subscript - 1, y);
}
double backwardPhi(const unsigned numberOfEntries, const double w, double const *x, double const *y)
{
    double s, h, temp = 0;
    h = x[1] - x[0];
    s = ((w - x[numberOfEntries - 1]) / h);
    for (int r = 0; r < numberOfEntries; r++)
    {
        temp += backwardCoeff(s, r) * backwardDel(r, numberOfEntries - 1, y);
    }
    return temp;
}
void printTable(const unsigned numberOfEntries, const double *x, const double *y)
{
    printf("\n");
    for (unsigned i = 0; i < numberOfEntries; i++)
    {
        printf("%lf\t", x[i]);
        for (unsigned j = 0; j < numberOfEntries; j++)
        {
            if (j > i)
                continue;
            printf("%lf\t", backwardDel(j, i, y));
        }
        printf("\n");
    }
}
void main()
{
    unsigned numberOfEntries;
    printf("How many entries do you have? ");
    scanf("%u", &numberOfEntries);
    double *x = (double *)malloc(numberOfEntries * sizeof(double));
    double *y = (double *)malloc(numberOfEntries * sizeof(double));
    double w; // variable to use finally is w

    takeInput(numberOfEntries, x, y);
    printTable(numberOfEntries, x, y);
    printf("Enter where to calculate f(x)\nx = ");
    scanf("%lf", &w);
    printf("f(%.2lf) = %.2lf", w, backwardPhi(numberOfEntries, w, x, y));
}