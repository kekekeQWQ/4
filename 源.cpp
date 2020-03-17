#include <stdlib.h>  
#include <stdio.h>
void merge(int X[], int Z[], int s, int u, int v)
{
	int i, j, q;
	i = s;
	j = u + 1;
	q = s;

	while (i <= u && j <= v)
	{
		if (X[i] <= X[j])
			Z[q++] = X[i++];
		else
			Z[q++] = X[j++];
	}

	while (i <= u) 
		Z[q++] = X[i++];
	while (j <= v)
		Z[q++] = X[j++];
}
void mergePass(int X[], int Y[], int n, int t)
{
	int i = 0, j;
	while (n - i >= 2 * t)
	{
		merge(X, Y, i, i + t - 1, i + 2 * t - 1);
		i = i + 2 * t;
	}

	if (n - i > t)
		merge(X, Y, i, i + t - 1, n - 1);
	else 
		for (j = i; j < n; ++j)
			Y[j] = X[j];
}

void mergeSort(int X[], int n)
{
	int t = 1;
	int *Y = (int *)malloc(sizeof(int) * n);
	while (t < n)
	{
		mergePass(X, Y, n, t);
		t *= 2;
		mergePass(Y, X, n, t);
		t *= 2;
	}
	free(Y);
}

void print_array(int array[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

int main()
{
	int array[] = { 65, 2, 6, 1, 90, 78, 105, 67, 35, 23, 3, 88, -22 };
	int size = sizeof(array) / sizeof(int);
	mergeSort(array, size);
	print_array(array, size);
	return 0;
}