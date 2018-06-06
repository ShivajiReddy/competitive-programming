#include <bits/stdc++.h>
using namespace std;

void check(string s)
{
	int length =  s.size(), count = 0;
	string h = "hello";
	for (int i = 0; i < length; ++i)
	{
		if(s[i] == h[count])
			count++;
	}
	if(count == 5) cout << "YES";
	else cout << "NO";

	return;
}

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	if(s.size() < 5) 
		cout << "NO";
	else check(s);

	return 0;
}
