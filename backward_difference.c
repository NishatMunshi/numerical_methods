#include <stdio.h>
int noe;
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
float prod(float s, int r)
{
    float t = 1;
    for (int i = 0; i < r; i++)
    {
        t *= (s + i);
    }
    t = t / fact(r);
    return t;
}
float del(int order, int subscript, float data[noe][2])
{
    if (order == 0)
        return data[subscript][1];
    else
        return del(order - 1, subscript, data) - del(order - 1, subscript - 1, data);
}
float phi(float data[noe][2], float x, int n)
{
    float s, h, temp = 0;
    h = data[1][0] - data[0][0];
    s = ((x - data[n][0]) / h);
    for (int i = 0; i < n + 1; i++)
    {
        temp += (prod(s, i) * del(i, n, data));
    }
    return temp;
}
void main()
{
    printf("Enter the number of entries of data you have: ");
    scanf("%d", &noe);
    float data[noe][2], x;
    int n = noe - 1;
    for (int i = 0; i < noe; i++)
    {
        printf("x%d = ", i);
        scanf("%f", &data[i][0]);
        printf("f(x%d) = ", i);
        scanf("%f", &data[i][1]);
    }
    printf("Enter where to calculate f(x)\nx = ");
    scanf("%f", &x);
    printf("f(%.2f) = %.2f", x, phi(data, x, n));
}