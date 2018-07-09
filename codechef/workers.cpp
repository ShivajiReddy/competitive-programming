#include <bits/stdc++.h>
using namespace std;

//std::map<key, value> map;
int main(int argc, char const *argv[])
{
	int n; cin >> n;
	long long min1, min2, min3;
	min1 = 100001;
	min2 = 100001;
	min3 = 100001;
	long long answer = 0;

	vector<long long> c(n);
	vector<int> t(n);
	for (int i = 0; i < n; ++i){ cin >> c[i]; }
	for (int i = 0; i < n; ++i){ cin >> t[i]; }
	
	for (int i = 0; i < n; i++)
	{
		long long x = c[i];
		if (t[i] == 1)
		{
			if (x < min1) min1 = x;
		}
		if (t[i] == 2)
		{
			if (x < min2) min2 = x;
		}
		if (t[i] == 3)
		{
			if (x < min3) min3 = x;
		}
	}
	//printf("min1: %llu  min2: %llu  min3: %llu\n", min1, min2, min3);
	answer = (min3 < (min1 + min2)) ? min3 : min1+min2;
	cout << answer << endl;

	return 0;
}
