#include <stdio.h>
#include <stdlib.h>
float f_v(int NOE, float table[0][NOE], float v) // NOE is number of entries
{
    float l_x, result = 0; // temp variable to return f_v // l_x is temp variable to store li(x). we initialize it by 1 in each iteration
    for (int i = 0; i < NOE; i++)
    {
        l_x = 1;
        for (int j = 0; j < NOE; j++)
        {
            if (i == j)
                continue;
            else
                l_x *= (v - table[0][j]) / (table[0][i] - table[0][j]);
        }
        result += table[1][i] * l_x;
    }
    return result;
}
void main()
{
    int NOE;
    printf("How many entries do you have ? ");
    scanf("%d", &NOE);
    float table[2][NOE]; // given table of values
    float v, fv = 0;                 // variable to use finally is v, fv is the approximation of f at x=v
    printf("\n");
    for (int i = 0; i < NOE; i++)
    {
        printf("x%d = ", i);
        scanf("%f", &table[0][i]);
        printf("f(x%d) = ", i);
        scanf("%f", &table[1][i]);
    }
    printf("\n");
    printf("\nWhich point to approximate f(x) at? ");
    scanf("%f", &v);
    fv = f_v(NOE, table, v);
    printf("\nThe value of f at x = %.2f is %.2f\n", v, fv);
}