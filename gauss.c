#include <stdio.h>
void printMatrix(const unsigned numberOfRows, const unsigned numberOfColumns, const double m[numberOfRows][numberOfColumns])
{
    for (unsigned i = 0; i < numberOfRows; i++)
    {
        for (unsigned j = 0; j < numberOfColumns; j++)
        {
            printf("%lf\t", m[i][j]);
        }
        printf("\n");
    }
}
int solvable(const unsigned numberOfEquations, const double a[numberOfEquations][numberOfEquations + 1], const unsigned iterationNumber)
{
    return a[iterationNumber][iterationNumber] == 0 ? 0 : 1;
}
void solve_Gauss(const unsigned numberOfEquations, double a[numberOfEquations][numberOfEquations + 1])
{
    double temp, temp2;

    // make upper triangular matrix
    for (unsigned i = 0; i < numberOfEquations; i++)
    {
        temp = a[i][i];
        if (!solvable(numberOfEquations, a, i))
        {
            printf("Not Solvable!");
            return;
        }
        for (unsigned j = 0; j < numberOfEquations + 1; j++)
        {
            a[i][j] /= temp;
        }
        for (unsigned numberOfRows = i + 1; numberOfRows < numberOfEquations; numberOfRows++)
        {
            temp2 = a[numberOfRows][i];
            // printf("%lf\numberOfEquations", temp2);
            for (unsigned j = 0; j < numberOfEquations + 1; j++)
            {
                a[numberOfRows][j] -= temp2 * a[i][j];
            }
        }
        for (unsigned j = 0; j < numberOfEquations + 1; j++)
        {
            a[i][j] *= temp;
        }
        printMatrix(numberOfEquations, numberOfEquations + 1, a);
        printf("\n");
    }

    // back substitution
    double x[numberOfEquations], temp3;
    for (int i = numberOfEquations - 1; i >= 0; i--)
    {
        temp = a[i][i];
        temp3 = 0;
        for (unsigned j = numberOfEquations - 1; j > i; j--)
        {
            temp3 += a[i][j] * x[j];
        }
        x[i] = (a[i][numberOfEquations] - temp3)/temp;
    }

    // print results
    printf("\nThe roots are: ");
    for (unsigned i = 0; i < numberOfEquations; i++)
    {
        printf("x%d = %lf\t", i + 1, x[i]);
    }
}
int main()
{
    unsigned numberOfEquations = 3;
    printf("Enter the number of equations: ");
    scanf("%u", &numberOfEquations);
    double a[numberOfEquations][numberOfEquations + 1];
    printf("Enter the augmented matrix:\n");
    for (unsigned i = 0; i < numberOfEquations; i++)
    {
        for (unsigned j = 0; j < numberOfEquations + 1; j++)
        {
            printf("a%u%u = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    // printMatrix(numberOfEquations, numberOfEquations + 1, a);
    solve_Gauss(numberOfEquations, a);
    return 0;
}