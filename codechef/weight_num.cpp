#include <bits/stdc++.h>
#include <string>
using namespace std;

int weight(int d)
{
	int w = 0;
	/*string s = to_string(d);
	for (int i = s.size()-1; i > 0 ; i--)
	{
		w = w + s[i]-s[i-1];
	}
	return w;*/
	while(d > 9)
	{
		int di, di1;
		di = d % 10;
		d = d/10;
		di1 = d %10;
		w += (di - di1);
	}
	return w;
}

int main(int argc, char const *argv[])
{
	int t; 
	cin >> t;
	while(t--)
	{
		int n, w, count = 0;
		cin >> n >> w;
		//int x = pow(10, n)-1;
		for (int j = pow(10, n-1); j < pow(10, n)-1; ++j)
		{
			if(weight(j) == w) count++;	
			//printf("weight(%d): %d\n", j, weight(j));
		}
		cout << count << endl;
	}

	return 0;
}