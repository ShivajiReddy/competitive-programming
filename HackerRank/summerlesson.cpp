#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	int c[n]; 
	int final[m] = {0};
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i];
	}

	for (int i = 0; i < n; ++i)
	{
		final[c[i]]++;
	}

	for (int i = 0; i < m; ++i)
	{
		cout << final[i] << " ";
	}

	
	

	return 0;
}