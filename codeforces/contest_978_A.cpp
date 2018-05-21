#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, count = 0;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	vector<int> dup(1001, 0);
	for (int i = n-1; i >= 0; i--)
	{
		if(dup[v[i]] == 0) 
		{
			dup[v[i]] = 1;
			count++;
		}
		else v[i] = 0;
			
	}
	//for(int i = 0; i < 10; i++){ cout << dup[i] << " ";}
	printf("%d\n", count);
	for (int i = 0; i < n; ++i)
	{
		if(v[i] != 0) 
			cout << v[i] << " ";
	}
	return 0;
}