#include <stdio.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter n:");
	scanf("%d", &n);

	int a[n][n], R[n][n];

	printf("Enter the adjacency matrix\n");
	for (int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
			R[i][j] = a[i][j];
		}
	}

	for (int k = 0; k < n; ++k)
	{
		for(int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; ++j)
			{
				R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
			}
		}
	}

	printf("The transitive closure is:\n");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ", R[i][j]);
		}
		printf("\n");
	}

/*
	R (0) ← A
for k ← 1 to n do
for i ← 1 to n do
for j ← 1 to n do
R (k) [i, j ] ← R (k−1) [i, j ] or (R (k−1) [i, k] and R (k−1) [k, j ])
(n)
return R*/
	return 0;
}