#include <bits/stdc++.h>
#include <string>


using namespace std;

int main(int argc, char const *argv[])
{
	/*int a[26];
	for (int i = 0; i < 26; ++i)
	{
		cin>>a[i];
	}*/
	int t; 
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		//Input
		cout<<"Input: ";	 
		string s; 
		cin >> s;
		int k; 
		cin >>k;

		//int strength;
		int l = s.length();
		cout<< s<<" Length: "<< l;

		//Strength
		for (int j = 0; j < l; j++)
		{
			int position = ((int)s[j]) - 'a' + 1;
			cout<<position;

		}	
	}
	return 0;
}