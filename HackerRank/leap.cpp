#include <bits/stdc++.h>

using namespace std;

bool isLeapYear(int x)
{
    return( (x%400 == 0) || (x%4 == 0 && x%100 !=0) );
}

int main(int argc, char const *argv[])
{
	int x; cin>>x;
	x = isLeapYear(x);
	cout<< x;
	return 0;
}