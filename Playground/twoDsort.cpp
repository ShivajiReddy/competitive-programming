#include <bits/stdc++.h>

using namespace std

int main(int argc, char const *argv[])
{
	vector<vector<int>> v;

	v = [[1,3], [10,2], [4,5]];
	sort(v.begin(),v.end());
	cout << v[1][0] << endl;
	
	return 0;
}