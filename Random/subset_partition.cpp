#include <bits/stdc++.h>
using namespace std;

bool partition(vector<int> v, int k)
{
	int n = v.size(), total_sum = accumulate(v.begin(), v.end(), 0);
	if(k < 1) return true;
	
	else if(k > n || total_sum%k != 0)
		return false;

	else
	{
		int sum = total_sum/k;
	}
}

int main(int argc, char const *argv[])
{
	int n, k; 
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++){ cin >> v[i]; }
	cout << partition(v, k) << endl;;

	return 0;
}