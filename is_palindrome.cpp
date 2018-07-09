#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;

	if(s == string(s.rbegin(), s.rend())) cout << "Palindrome!\n";
	else cout << "Not a Palindrome";
	
	return 0;
}
