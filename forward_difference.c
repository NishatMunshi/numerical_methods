#include <stdio.h>
int noe;
void takeInput(float data[noe][2]) //takes first two x inputs and fills the rest of x's.
{
    for (int i = 0; i < 2; i++)
    {
        printf("x%d = ", i);
        scanf("%f", &data[i][0]);
    }
    for(int i = 0; i < noe; i++)
    {
        printf("f(x%d) = ", i);
        scanf("%f", &data[i][1]);
    }
    for(int i = 2; i < noe; i++)
    {
        data[i][0]=data[i-1][0]+data[0][0];
    }
}
int fact(int n)
{
    if (n == 0 || n == 0)
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
int comb(int s, int r)
{
    return fact(s) / (fact(r) * fact(s - r));
}
float del(int order, int subscript, float data[noe][2])
{
    if (order == 0)
        return data[subscript][1];
    else
        return del(order - 1, subscript + 1, data) - del(order - 1, subscript, data);
}
float phi(float x, float data[noe][2])
{
    int s;
    float h, temp = 0;
    h = data[1][0] - data[0][0];
    s = (int)((x - data[0][0]) / h);
    for (int r = 0; r < noe; r++)
    {
        temp += comb(s, r) * del(r, 0, data);
    }
    return temp;
}
void main()
{
    printf("Enter the number of entries of data you have: ");
    scanf("%d", &noe);
    float data[noe][2];
    float x;
    takeInput(data);
    printf("Enter where to calculate f(x)\nx = ");
    scanf("%f", &x);
    printf("f(%.2f) = %.2f", x, phi(x, data));
}