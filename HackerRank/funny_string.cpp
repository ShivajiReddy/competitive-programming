#include <bits/stdc++.h>
using namespace std;

int abs(int x)
{
	return (x>0) ? x : -1*x;
}

string is_funny(string s)
{
	string r = s;
	reverse(r.begin(),r.end());
	for (int i = 1; i < s.length(); ++i)
	{
		if( abs( (int)s[i] - (int)s[i-1] )	!=	abs( (int)r[i] - (int)r[i-1] ) )
			return "Not Funny";	
	}

	return "Funny";
}

int main(int argc, char const *argv[])
{
	int t; cin >> t;
	for (int i = 0; i < t; ++i)
	{
		string s;
		cin>>s;
		string result = is_funny(s);
		cout<< result<<endl;
	}
		return 0;
}