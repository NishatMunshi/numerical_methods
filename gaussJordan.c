#include <stdio.h>
void printMatrix(const unsigned r, const unsigned c, const double m[r][c])
{
    for (unsigned i = 0; i < r; i++)
    {
        for (unsigned j = 0; j < c; j++)
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
void solve_GaussJordan(const unsigned numberOfEquations, double a[numberOfEquations][numberOfEquations + 1])
{
    double temp, temp2;
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
        for (unsigned r = 0; r < numberOfEquations; r++)
        {
            if (r == i)
                continue;
            else
            {
                temp2 = a[r][i];
                for (unsigned j = 0; j < numberOfEquations + 1; j++)
                {
                    a[r][j] -= temp2 * a[i][j];
                }
            }
        }
    }
    printf("\nThe roots are: ");
    for (unsigned i = 0; i < numberOfEquations; i++)
    {
        printf("x%d = %lf\t", i + 1, a[i][numberOfEquations]);
    }
}
// int main()
// {
//     unsigned numberOfEquations = 3;
//     printf("Enter the number of equations: ");
//     scanf("%u", &numberOfEquations);
//     double a[numberOfEquations][numberOfEquations + 1];
//     printf("Enter the augmented matrix:\numberOfEquations");
//     for (unsigned i = 0; i < numberOfEquations; i++)
//     {
//         for (unsigned j = 0; j < numberOfEquations + 1; j++)
//         {
//             printf("a%u%u = ", i, j);
//             scanf("%lf", &a[i][j]);
//         }
//     }
//     // printMatrix(numberOfEquations, numberOfEquations + 1, a);
//     solve_GaussJordan(numberOfEquations, a);
    
//     return 0;
// }
