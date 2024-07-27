#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
double forwardDel(const int order, const int subscript, double const *y)
{
    if (order == 0)
        return y[subscript];
    else
        return forwardDel(order - 1, subscript + 1, y) - forwardDel(order - 1, subscript, y);
}
double backwardDel(const int order, const int subscript, double const *y)
{
    if (order == 0)
        return y[subscript];
    else
        return backwardDel(order - 1, subscript, y) - backwardDel(order - 1, subscript - 1, y);
}
float D_x0(const unsigned numberOfEntries, double const *x, double const *y)
{
    float temp = 0, h = x[1] - x[0];
    for (int i = 1; i < numberOfEntries; i++)
    {
        temp += pow(-1, 1 + i) * forwardDel(i, 0, y) / i;
    }
    temp = temp / h;
    return temp;
}
float D_xn(const unsigned numberOfEntries, double const *x, double const *y)
{
    float temp = 0, h = x[1] - x[0];
    for (int i = 1; i < numberOfEntries; i++)
    {
        temp += backwardDel(i, numberOfEntries - 1, y) / i;
    }
    temp = temp / h;
    return temp;
}
void main()
{
    unsigned numberOfEntries;
    printf("How many entries do you have? ");
    scanf("%u", &numberOfEntries);
    double *x = (double *)malloc(numberOfEntries * sizeof(double));
    double *y = (double *)malloc(numberOfEntries * sizeof(double));
    takeInput(numberOfEntries, x, y);
    printf("The derivative at x = %.2f is %f\n", x[0], D_x0(numberOfEntries, x, y));
    printf("The derivative at x = %.2f is %f\n", x[numberOfEntries - 1], D_xn(numberOfEntries, x, y));
}