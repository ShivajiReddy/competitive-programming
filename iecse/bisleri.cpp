#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
	vector<int> v(10, 0);
    vector<int> letters;
    int length = s.size();
    for (int i = 0; i < length; i++)
    {
        int digit = (s[i]-'0');
        v[digit]++;
    }
    /*for (int i = 0; i < 10; ++i)
    {
        cout << v[i] << " ";
    }*/

    if(v[6] > 1) letters.push_back(66);
    if(v[7] > 1) letters.push_back(77);
    for (int i = 6; i <= 9; ++i)
    {
        if(v[i] != 0)
        {
            for (int j = 0; j < 10; ++j)
            {
                if(v[j] != 0 && i != j) 
                {
                    int number = (i*10) + j;
                    if(number >= 65 && number <= 90) letters.push_back(number);
                }

                //{ letters.push_back((i*10) + j); }
            }
        }
    }
    sort(letters.begin(), letters.end());
    for (int i = 0; i < letters.size(); ++i)
    {
        cout << (char)letters[i];
    }
    cout << endl;

}

int main()
{
    int t; 
    cin >> t;
    string input[t];
    for (int i = 0; i < t; ++i)
    {
        cin >> input[i];
    }
    for (int j = 0; j < t; ++j)
    {
        string s = input[j];
        solve(s);   
    }
    
    return 0;
};