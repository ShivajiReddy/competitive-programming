#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
	int n; 
	cin>>n;
	if(n%3 == 1) n = n+2;
	if(n%3 == 2) n++;

	int a[n+3] = {0};
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	int b[3];
	for (int i = 0; i < n; i++)
	{
		int x = i % 3;
		if(x == 0)
		{
			b[0] += a[i];
		}
		else if(x == 1)
		{
			b[1] += a[i];
		}

		else  if(x == 2)
		{
			b[2] += a[i];
		}
	}
		
	for (int i = 0; i < 3; ++i)
	{
		cout<<b[i]<<" ";
	}
	return 0;
} 