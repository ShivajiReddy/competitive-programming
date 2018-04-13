#include <bits/stdc++.h>
using namespace std;

int larger(int x, int y)
{
	return (x>y) ? x : y;
}

//Pretty efficient
int max_sum(vector <int> a)
{	int n = a.size();
	int best = 0, sum = 0;
	for (int k = 0; k < n; k++) 
	{
		sum = larger(a[k],sum+a[k]);
		best = larger(best,sum);
	}

	return best;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector <int> a;
	for (int i = 0; i < n; i++)
	{
		int k; cin >> k;
		a.push_back(k);
	}

	int x = max_sum(a);
	cout<< x << endl;
	return 0;
}	