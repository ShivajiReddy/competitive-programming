#include <stdio.h>
#include <math.g>

int generate_subsets(int n, int [], int subsets[][n])
{
	
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int a[n];

	for(int i = 0; i < n; i++){ scanf("%d", &a[i]); }
	int subsets[pow(2, n)][n] = generate_subsets(n, a, subsets);
	
	return 0;
}