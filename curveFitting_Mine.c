#include "gaussJordan.c"
#include <math.h>
double sum(const unsigned numberOfEntries, const double *ptr){
    double temp = 0.0;
    for(unsigned i = 0; i < numberOfEntries; i++)
    {
        temp += *(ptr + i);
    }
    return temp;
}
void fillAugmented(const unsigned numberOfEntries, const unsigned degree, const double p[2][numberOfEntries], double a[degree+1][degree+2]){
    double temp[2*degree+1][numberOfEntries]; // matrix whose rows hold all the powers of x
    for(unsigned i = 0; i < degree*2+1; i++)
    {
        for(unsigned j = 0; j < numberOfEntries; j++)
        {
            temp[i][j] = pow(p[0][j], i);
        }
    }
    double temp2[degree+1][numberOfEntries];  // matrix whose rows hold all (x^r)y values
    for(unsigned i = 0; i < degree+1; i++)
    {
        for(unsigned j = 0; j < numberOfEntries; j++)
        {
            temp2[i][j] = temp[i][j]*p[1][j];
        }
    } 

    //filling augmented matrix
    for(unsigned i = 0; i < degree+1; i++)
    {
        for(unsigned j = 0; j < degree+1; j++)
        {
            a[i][j] = sum(numberOfEntries, temp[i+j]);
        }
        a[i][degree+1] = sum(numberOfEntries, temp2[i]);
    }
}
int main()
{
    unsigned numberOfEntries, degree;
    printf("Enter number of data points: ");
    scanf("%u", &numberOfEntries);
    double p[2][numberOfEntries];   // data points
    for(unsigned j = 0; j < numberOfEntries; j++)
    {
        printf("x%u = ", j+1);
        scanf("%lf", &p[0][j]);
    }
    for(unsigned j = 0; j < numberOfEntries; j++)
    {
        printf("y%u = ", j+1);
        scanf("%lf", &p[1][j]);
    }
    printf("Enter the degree of polynomial you need: ");
    scanf("%u", &degree);
    double a[degree+1][degree+2];  // augmented matrix to solve.
    fillAugmented(numberOfEntries, degree, p, a);
    solve_GaussJordan(degree+1, a);
    printf("\nThe best fit curve is:\ny = ");
    for(unsigned i = 0; i < degree+1; i++)
    {
        printf(" + (%lf)x^%u", a[i][degree+1], i);
    }
    return 0;
}