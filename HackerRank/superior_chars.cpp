#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	while(t--)
	{
		double frequency[26], sum = 0;
		for(int i = 0; i < 26; i++){ cin >> frequency[i]; }
		
		for (int i = 0; i < 25; ++i)
		{
			sum += frequency[i];
		}
		cout << sum/2 << endl;
	}	

	return 0;
}