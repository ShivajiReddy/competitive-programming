#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n; 
	cin >> n;
	string t[n];
	long y[n], x = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> t[i];
		cin >> y[i];
	}

	for (int i = 0; i < n; ++i)
	{
		if(t[i][0] == 's' && y[i] > x)
			x = y[i];

		if(t[i][0] == 'a' && x + y[i] > x)
			x += y[i];
	}

	cout << x << endl;


	return 0;
}						