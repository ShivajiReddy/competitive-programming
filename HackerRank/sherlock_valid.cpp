#include <bits/stdc++.h>
using namespace std;

string is_valid(string s)
{
	string r = "YES";
	int a[26] = {0};
	for (int i = 0; i < s.length(); ++i)
	{
		a[(int)s[i] - 'a']++;
	}
	vector <int> v;
	
	int sum = 0;
	for (int i = 0; i < 26; ++i)
	{
		if(a[i] != 0)
		{
			v.push_back(a[i]);
			sum += a[i];
		} 
	}

	for (int i = 0; i < v.size() ; ++i)
	{
		if( v[i] != (sum/v.size())) return "NO";
	}

	return r;
}

int main(int argc, char const *argv[])
{
	string s, result;
	cin >> s;
	result = is_valid(s);
	cout << result << endl;
	return 0;
}