#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, x, tracker = 0, life = 0;
	cin >> n >> x;
	int a[n]; 
	int result[n] = {0};

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i)
	{
		if (a[i] <= x)
		{
			result[tracker]++;
			if (i != n-1 && a[i+1] > x)
			{
				if (life == 0)
				{
					life++;
				}
				else tracker++;
			}
		}
	}

	sort(a, a+n, greater<int>());
	cout << result[0];

	return 0;
}