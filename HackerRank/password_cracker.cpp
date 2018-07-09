#include <bits/stdc++.h>

using namespace std;

string passwordCracker(vector <string> pass, string attempt) 
{
	
}

int main() 
{
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<string> pass(n);
        for(int pass_i = 0; pass_i < n; pass_i++){
        	cin >> pass[pass_i];
        }
        string attempt;
        cin >> attempt;
        string result = passwordCracker(pass, attempt);
        cout << result << endl;
    }
    return 0;
}