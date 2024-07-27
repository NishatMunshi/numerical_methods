#include <stdio.h>

int equals(float a, float b)
{
	float e = 0.000001; // error
	return (a - b <= e) && (a - b >= -e);
}
void swapRows(int m, float a[m + 1][m + 2], int x, int y)
{
	if (x == y)
		return;
	int i;
	float temp;
	for (i = 0; i < m + 2; i++)
	{
		temp = a[x][i];
		a[x][i] = a[y][i];
		a[y][i] = temp;
	}
}
float raise(float x, int n)
{
	if (x == 0)
		return 0;
	if (n == 0)
		return 1.0;
	if (n % 2 == 0)
		return raise(x * x, n / 2);
	return x * raise(x, n - 1);
}
float sum(int n, float x[n], float y[n], int xp, int yp)
{
	int i;
	float ans = 0;
	for (i = 0; i < n; i++)
	{
		if (yp != 0)
			ans += raise(x[i], xp) * raise(y[i], yp);
		else
			ans += raise(x[i], xp);
	}
	return ans;
}
void generateAugmented(int m, float a[m + 1][m + 2], int n, float x[n], float y[n])
{
	int i, j;
	for (i = 0; i <= m; i++)
	{
		for (j = i; j <= m; j++)
		{
			a[i][j] = sum(n, x, y, i + j, 0);
			//			printf("a[%d][%d] = %f\n", i, j, a[i][j]);
			a[j][i] = a[i][j];
			//			printf("a[%d][%d] = %f\n", j, i, a[j][i]);
		}
	}
	for (i = 0; i <= m; i++)
	{
		a[i][m + 1] = sum(n, x, y, i, 1);
		//		printf("a[%d][%d] = %f\n", i, m+1, a[i][m+1]);
	}
}
int solveGaussJordan(int m, float a[m + 1][m + 2], float coeff[m + 1])
{
	int i, j, k;
	for (i = 0; i <= m; i++)
	{
		int noUnique = 1;
		for (j = i; j <= m; j++)
		{
			if (!equals(a[j][i], 0.0))
			{
				noUnique = 0;
				break;
			}
		}
		if (noUnique)
			return 0;
		swapRows(m, a, i, j);
		if (!equals(a[i][i], 1.0))
		{
			float val = a[i][i];
			for (k = 0; k <= m + 1; k++)
			{
				a[i][k] /= val;
			}
		}
		for (j = 0; j <= m; j++)
		{
			if (j == i)
				continue;
			float val = a[j][i];
			if (equals(val, 0.0))
				continue;
			for (k = 0; k <= m + 1; k++)
			{
				a[j][k] = a[j][k] - a[i][k] * val;
			}
		}
	}
	for (i = 0; i <= m; i++)
	{
		coeff[i] = a[i][m + 1];
	}
	return 1;
}
int main()
{
	int n, m, i, j;
	printf("Enter the number of data points: ");
	scanf("%d", &n);
	printf("Enter X and Y coordinates of the %d points: \n", n);
	float x[n], y[n];
	for (i = 0; i < n; i++)
	{
		printf("Point-%d: ", i + 1);
		scanf("%f %f", &x[i], &y[i]);
	}
	printf("Enter the degree of the best-fit curve: ");
	scanf("%d", &m);
	float a[m + 1][m + 2];
	float coeff[m + 1];
	for (i = 0; i < m + 1; i++)
	{
		for (j = 0; j < m + 2; j++)
		{
			a[i][j] = 0.0;
		}
	}
	generateAugmented(m, a, n, x, y);
	//	for(i=0; i<m+1; i++){
	//		for(j=0; j<m+2; j++){
	//			printf("%f ", a[i][j]);
	//		}
	//		printf("\n");
	//	}
	if (!solveGaussJordan(m, a, coeff))
	{
		printf("Best-fit curve with given specifications cannot be generated!\n");
		return 0;
	}
	printf("Best fit curve is: \nf(x) = ");
	for (i = m; i >= 0; i--)
	{
		if (coeff[i] < 0.0)
		{
			printf("- ");
			coeff[i] *= -1;
		}
		else
		{
			if (i != m)
			{
				printf("+ ");
			}
		}
		if (i == 0)
		{
			printf("%f\n", coeff[i]);
			break;
		}
		printf("%f*x^%d ", coeff[i], i);
	}
	return 0;
}
