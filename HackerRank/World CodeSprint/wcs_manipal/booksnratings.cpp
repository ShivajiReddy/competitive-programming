#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
	return (x>y) ? x : y;
}

//Pretty efficient	
int max_sum(vector <int> a)
{	int n = a.size();
	int best = 0, sum = 0;
	for (int k = 0; k < n; k++) 
	{
		sum = max(a[k],sum+a[k]);
		best = max(best,sum);
	}

	return best;
}

int main(int argc, char const *argv[])
{
	

	int x = max_sum(a);
	cout<<x <<"\n";
	return 0;
}