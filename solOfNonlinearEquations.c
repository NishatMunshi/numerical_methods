#include <stdio.h>
#include <math.h>
double f(const double x)
{
    return x * x * x * x - 8 * x * x - 24 * x + 7;
}
double fDash(const double x)
{
    return 4 * x * x * x - 16 * x - 24;
}
double mod(const double x)
{
    return x >= 0 ? x : -x;
}
double bisection(double a, double b, const double maxAllowedError, const unsigned maxNumberOfIterations)
{
    double xi = (a + b) / 2;
    unsigned k = 0;
    while (1)
    {
        if (k == maxNumberOfIterations)
        {
            printf("Reached max number of iterations.\n");
            break;
        }
        if (mod(f(xi)) <= maxAllowedError)
        {
            printf("Found after iteration %u\n", k + 1);
            break;
        }
        else if (f(a) * f(xi) < 0)
        {
            b = xi;
            xi = (a + b) / 2;
        }
        else if (f(xi) * f(b) < 0)
        {
            a = xi;
            xi = (a + b) / 2;
        }
        k++;
    }
    return xi;
}
double regulaFalsi(double a, double b, const double maxAllowedError, const unsigned maxNumberOfIterations)
{
    double xi = b - (f(b) * (b - a) / (f(b) - f(a)));
    unsigned k = 0;
    while (1)
    {
        if (k == maxNumberOfIterations)
        {
            printf("Reached max number of iterations.\n");
            break;
        }
        if (mod(f(xi)) <= maxAllowedError)
        {
            printf("Found after iteration %u\n", k + 1);
            break;
        }
        else if (f(a) * f(xi) < 0)
        {
            b = xi;
            xi = b - (f(b) * (b - a) / (f(b) - f(a)));
        }
        else if (f(xi) * f(b) < 0)
        {
            a = xi;
            xi = b - (f(b) * (b - a) / (f(b) - f(a)));
        }
        k++;
    }
    return xi;
}
double newtonRaphson(double b, const double maxAllowedError, const unsigned maxNumberOfIterations)
{
    double xi = b - f(b) / fDash(b);
    unsigned k = 0;
    while (1)
    {
        if (k == maxNumberOfIterations)
        {
            printf("Reached max number of iterations.\n");
            break;
        }
        if (mod(f(xi)) <= maxAllowedError)
        {
            printf("Found after iteration %u\n", k + 1);
            break;
        }
        else
        {
            b = xi;
            xi = b - f(b) / fDash(b);
        }
        k++;
    }
    return xi;
}
void main()
{
    unsigned choice, maxNumberOfIterations;
    double a, b, maxAllowedError;
    while (1)
    {
    repeat:
        printf("\nEnter initial estimates:\na = ");
        scanf("%lf", &a);
        printf("b = ");
        scanf("%lf", &b);
        printf("Enter max allowed error: ");
        scanf("%lf", &maxAllowedError);
        printf("Enter max number of iterations: ");
        scanf("%u", &maxNumberOfIterations);
        printf("\n\nChoose what method to use:\n0. Quit programme\n1. Bisection\n2. Regula Falsi\n3. Newton Raphson\n");
        scanf("%u", &choice);
        switch (choice)
        {
        case 0:
            goto end;
            break;
        case 1:
            printf("root is %lf\n", bisection(a, b, maxAllowedError, maxNumberOfIterations));
            break;
        case 2:
            printf("root is %lf\n", regulaFalsi(a, b, maxAllowedError, maxNumberOfIterations));

            break;
        case 3:
            printf("root is %lf\n", newtonRaphson(b, maxAllowedError, maxNumberOfIterations));

            break;

        default:
            printf("Invalid Choice!!");
            goto repeat;
            break;
        }
    }
end:
}
