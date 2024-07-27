#include <stdio.h>
#define CONVERGENCE_TOLERANCE 0.000001
double change(const unsigned numberOfEquations, const double x[numberOfEquations], const double temp_x[numberOfEquations])
{
    double temp;
    for (unsigned i = 0; i < numberOfEquations; i++)
    {
        temp += (x[i] - temp_x[i]) * (x[i] - temp_x[i]);
    }
    return temp;
}

void solve_jacobi(const unsigned numberOfEquations, const double a[numberOfEquations][numberOfEquations + 1], double x[numberOfEquations], const unsigned limitOfIterations)
{
    double temp, temp_x[numberOfEquations];
    unsigned k = 1;
    while (1)
    {
        // initializing temp_x for every iteration
        for (unsigned i = 0; i < numberOfEquations; i++)
        {
            temp_x[i] = x[i];
        }

        // updating x's
        for (unsigned i = 0; i < numberOfEquations; i++)
        {
            temp = 0;
            for (unsigned j = 0; j < numberOfEquations; j++)
            {
                if (i == j)
                    continue;
                temp += a[i][j] * temp_x[j];
            }
            x[i] = (a[i][numberOfEquations] - temp) / a[i][i];
        }
        printf("\nThe roots of iteartion %u are: ", k);
        for (unsigned i = 0; i < numberOfEquations; i++)
        {
            printf("x%d = %.3lf\t", i + 1, x[i]);
        }
        if (change(numberOfEquations, x, temp_x) <= CONVERGENCE_TOLERANCE || k == limitOfIterations)
        {
            if (k == limitOfIterations)
            {
                printf("\n\n*****Reached the limitOfIterations.*****");
                goto end;
            }
            else if (change(numberOfEquations, x, temp_x) <= CONVERGENCE_TOLERANCE)
                printf("\n\n*****Found it!!*****");
            break;
        }
        k++;
    }
    printf("\n\nFinally the roots are: ");
    for (unsigned i = 0; i < numberOfEquations; i++)
    {
        printf("x%d = %.3lf\t", i + 1, x[i]);
    }
end:
}

int main()
{
    unsigned numberOfEquations = 3, limitOfIterations = 100;
    printf("Enter the number of equations: ");
    scanf("%u", &numberOfEquations);
    double a[numberOfEquations][numberOfEquations + 1], x[numberOfEquations];
    printf("Enter the augmented matrix:\n");
    for (unsigned i = 0; i < numberOfEquations; i++)
    {
        for (unsigned j = 0; j < numberOfEquations + 1; j++)
        {
            printf("a%u%u = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    printf("Enter the limitOfIterations of iterations: ");
    scanf("%u", &limitOfIterations);
    while (1)
    {
        printf("\n\nEnter initial estimate of roots:\n");
        for (unsigned i = 0; i < numberOfEquations; i++)
        {
            printf("x%u = ", i + 1);
            scanf("%lf", &x[i]);
        }
        solve_jacobi(numberOfEquations, a, x, limitOfIterations);
    }
    return 0;
}