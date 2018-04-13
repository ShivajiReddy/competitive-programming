#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int b, c, desc;
	cin >> b >> c;

	desc = (b*b)-(4*c);
	if(b > 0) cout << "1\n";
	else cout << "0";
	return 0;
}