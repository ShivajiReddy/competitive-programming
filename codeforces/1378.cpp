#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//This thin works!
	long long x = 8, n;
	cin >> n;
	if(n == 1) cout << 8;
	if(n == 2) cout << 4;
	if(n == 3) cout << 2;
	if(n > 3)
	{
		if(n%4 == 0) cout << 6;
		if(n%4 == 1) cout << 8;
		if(n%4 == 2) cout << 4;
		if(n%3 == 3) cout << 2;
	}


	/*else
	{
		for(int i = 2; i <= n; i++)
		{
			x = x*8;
			x = x % 10;
			//printf("%d: %d  ", i, x%10);
			//if(i = n-1) cout << x%10;
		}
		cout << x << endl;
	}*/
		
	return 0;
}