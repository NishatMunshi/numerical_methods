#include <stdio.h>
#include<math.h>
float f(const float x)
{
    return x*sin(x)/(1+x*x); // Edit this line according to the function.
}
void fillData(const float a, const float b, const int numberOfIntervals, float data[][2])
{   
    data[0][0]=a;
    for (int i = 1; i < numberOfIntervals+1; i++)
    {
       data[i][0]=a+i*(b-a)/(float)numberOfIntervals; 
    //    printf("%f  ", data[i][0]);       DEBUGGING
    }
    for(int i = 0; i < numberOfIntervals+1; i++)
    {
        data[i][1]=f(data[i][0]);
    //    printf("%f  ", data[i][1]);       DEBUGGING

    }
}
float integral(const float a,const float b,const int numberOfIntervals,const float data[][2])
{
    float temp = 0;
    for (int i = 0; i < numberOfIntervals / 2; i++)
    {
        temp += 4 * data[2 * i + 1][1];
    }
    for (int i = 1; i <= (numberOfIntervals - 2) / 2; i++)
    {
        temp += 2 * data[2 * i][1];
    }
    temp += f(a) + f(b);
    temp *= (b - a) / (3 * (numberOfIntervals));
    return temp;
}
void main()
{
    int N;
    float a, b;
repeat:
    printf("\nEnter number of intervals : ");
    scanf("%d", &N);
    if (N%2!=0)
    {
        printf("numberOfIntervals cannot be odd.\n");
        goto repeat;
    }
    
    printf("Enter the bounds:\na = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    const int numberOfIntervals = N;
    float h = (b - a) / numberOfIntervals , data[numberOfIntervals+1][2];
    fillData(a,b,numberOfIntervals,data);
    printf("The value of the intgral from x = %.2f to x = %.2f is %.4f\n", a, b, integral(a, b, numberOfIntervals, data));
}