#include <bits/stdc++.h>

using namespace std;

int minSteps(int n, string s)
{
	int steps = 0;
    for (int i = 0; i < n-2; ++i)
    {
    	if(s[i] == '0' && s[i+1] == '1' && s[i+2] == '0') 
    	{
    		s[i+2] = '1';
    		steps++;
    	}

    }
	//if(steps != 0) return steps-1;
	//else return steps;
	return steps;
}

int main() 
{
    int n;
    cin >> n;
    string B;
    cin >> B;
    int result = minSteps(n, B);
    cout << result << endl;
    return 0;
}
