#include <math.h>
#include <stdio.h>
#define MAX_ALLOWED_ERROR 0.000001
double mod(const double x)
{
    return x >= 0 ? x : -x;
}
int equals(const double a, const double b)
{
    return mod(a - b) <= MAX_ALLOWED_ERROR ? 1 : 0;
}
double DyDx(const double x, const double y)
{
    return x *x+y*y; // change this according to need
}
double euler(double *x, double y, const double xn, const double h)
{
    unsigned steps = (unsigned)((xn - *x) / h);
    double dydx;
    // filling x array
    for (unsigned i = 0; i < steps; i++)
    {
        x[i] = x[0] + i * h;
    }
    for (unsigned i = 0; i < steps; i++)
    {
        dydx = DyDx(*(x + i), y);
        y += h * dydx;
    }
    return y;
}
double eulerModified(double *x, double y, const double xn, const double h)
{
    unsigned steps = (unsigned)((xn - *x) / h);
    double t1, t2, mean = 0; // t1 for storing initial y starting point , t2 for storing initial dydx
    for (unsigned i = 0; i < steps; i++)
    {
        // intial step
        mean = 0;
        t1 = y;
        t2 = DyDx(*(x + i), y);
        x[i + 1] = x[i] + h;
        y = t1 + h * t2;
        // printf("y init = %.4lf\n", y); //DEBUG
        // iterative step
        while (1)
        {
            mean = (t2 + DyDx(*(x + i + 1), y)) / 2;
            // printf("x+i+1 = %.4lf\n", *(x+i+1)); //DEBUG
            if (equals(y, t1 + h * mean))
                break;
            y = t1 + h * mean;
            // printf("y = %.4lf\n", y); //DEBUG
        }
    }
    return y;
}
double runge(const double x, const double y, const double xn)
{
    const double h = xn - x;
    const double k1 = h * DyDx(x, y);
    const double k2 = h * DyDx(x + h / 2, y + k1 / 2);
    const double kdash = h * DyDx(x + h, y + k1);
    const double k3 = h * DyDx(x + h, y + kdash);
    const double k = (k1 + 4 * k2 + k3) / 6;
    return y + k;
}
double rungeKutta(const double x, const double y, const double xn)
{
    const double h = xn - x;
    const double k1 = h * DyDx(x, y);
    const double k2 = h * DyDx(x + h / 2, y + k1 / 2);
    const double k3 = h * DyDx(x + h / 2, y + k2 / 2);
    const double k4 = h * DyDx(x + h, y + k3);
    const double k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    return y + k;
}
int main()
{
    double x[50], y, xn, h;
    unsigned choice;
    printf("\nEnter boundary condition:\nx0 = ");
    scanf("%lf", x);
    printf("y0 = ");
    scanf("%lf", &y);
    printf("Where to calculate? x = ");
    scanf("%lf", &xn);
    printf("Choose method:\n1. Euler's Method\n2. Euler's Modified Method\n3. Runge's Method\n4. Runge-Kutta Method\n");
    scanf("%u", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter h: ");
        scanf("%lf", &h);
        printf("\ny at x = %lf is: %lf", xn, euler(x, y, xn, h));
        break;

    case 2:
        printf("Enter h: ");
        scanf("%lf", &h);
        printf("\ny at x = %lf is: %lf", xn, eulerModified(x, y, xn, h));
        break;

    case 3:
        printf("\ny at x = %lf is: %lf", xn, runge(*x, y, xn));
        break;

    case 4:
        printf("\ny at x = %lf is: %lf", xn, rungeKutta(*x, y, xn));
        break;

    default:
        break;
    }

    return 0;
}