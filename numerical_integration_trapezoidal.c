#include <stdio.h>
#include <math.h>
float f(const float x)
{
    return 1/x; // Edit this line according to the function.
}
void fillData(const float a, const float b, const int n, float data[][2])
{
    data[0][0] = a;
    for (int i = 1; i < n + 1; i++)
    {
        data[i][0] = a + i * (b - a) / n;
    }
    for (int i = 0; i < n + 1; i++)
    {
        data[i][1] = f(data[i][0]);
    }
}
float integral(const float a, const float b, const int n, float data[][2])
{
    float h = (b - a) / n, temp = 0;
    for (int i = 0; i < n + 1; i++)
    {
        temp += data[i][1];
    }
    for (int i = 1; i < n; i++)
    {
        temp += data[i][1];
    }
    temp *= (h / 2);
    return temp;
}
void main()
{
    int N;
    float a, b;
    printf("\nEnter number of intervals n: ");
    scanf("%d", &N);
    printf("Enter the bounds:\na = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    const int n = N;
    float h = (b - a) / n, data[n + 1][2];
    fillData(a, b, n, data);
    printf("The value of the intgral from x = %.2f to x = %.2f is %f\n", a, b, integral(a, b, n, data));
}