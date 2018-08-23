#include <stdio.h>
#include <math.g>

int

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int a[n];

	for(int i = 0; i < n; i++){ scanf("%d", &a[i]); }
	int subsets[pow(2, n)][n] = generate_subsets(a, subsets);
	
	return 0;
}