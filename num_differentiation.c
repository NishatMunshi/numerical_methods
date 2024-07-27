#include <stdio.h>
#include <math.h>
int noe;
void takeInput(float data[noe][2]) // takes first two x inputs and fills the rest of x's.
{
    for (int i = 0; i < 2; i++)
    {
        printf("x%d = ", i);
        scanf("%f", &data[i][0]);
    }
    for (int i = 0; i < noe; i++)
    {
        printf("f(x%d) = ", i);
        scanf("%f", &data[i][1]);
    }
    for (int i = 2; i < noe; i++)
    {
        data[i][0] = data[0][0] + i*(data[1][0]-data[0][0]);
    }
}
float forward_del(int order, int subscript, float data[noe][2])
{
    if (order == 0)
        return data[subscript][1];
    else
        return forward_del(order - 1, subscript + 1, data) - forward_del(order - 1, subscript, data);
}
float backward_del(int order, int subscript, float data[noe][2])
{
    if (order == 0)
        return data[subscript][1];
    else
        return backward_del(order - 1, subscript, data) - backward_del(order - 1, subscript - 1, data);
}
float D_x0(float data[noe][2])
{
    float temp = 0, h = data[1][0] - data[0][0];
    for (int i = 1; i < noe; i++)
    {
        temp += pow(-1, 1+i) * forward_del(i, 0, data) / i;
    }
    temp = temp / h;
    return temp;
}
float D_xn(float data[noe][2])
{
    float temp = 0, h = data[1][0] - data[0][0];
    for (int i = 1; i < noe; i++)
    {
        temp += backward_del(i, 0, data) / i;
    }
    temp = temp / h;
    return temp;
}
void main()
{
    printf("How many entries of data do you have?\n");
    scanf("%d", &noe);
    float data[noe][2];
    printf("Enter the data:\n");
    takeInput(data);
    printf("The derivative at x = %.2f is %f\n", data[0][0], D_x0(data));
    printf("The derivative at x = %.2f is %f\n", data[noe-1][0], D_xn(data));
}