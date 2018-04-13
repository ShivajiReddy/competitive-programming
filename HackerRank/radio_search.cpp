#include <bits/stdc++.h>

using namespace std; 

int main(int argc, char const *argv[])
{
	int n, k;
	int counter = 0;
	cin >> n >> k;
	vector<int> x(n);
	
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	sort(x.begin(), x.end());

	int i = 0;
	while (i < n) 
	{
    	counter++;
    	int loc = x[i] + k;
    	while (i < n && x[i] <= loc) i++;
    	loc = x[i-1] + k;
    	while (i < n && x[i] <= loc) i++;
	}
	cout << counter << endl;
	return 0;
}