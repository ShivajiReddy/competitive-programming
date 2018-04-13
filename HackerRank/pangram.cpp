#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

//SUCH A SHAMEEE

string is_pangram(string s)
{
	transform(s.begin(), s.end(), s.begin(), tolower);

    cout<<s<<endl;
    
    return s;
    /*for(int i = 0; i < s.length(); i++)
    {
        a[(int)s[i] - 'a']++;
    }
        
    for(int i = 0; i < 26; i++)
    {
        if(a[i] == 0) 
        {
            cout<<"not pangram";
            return 0;
        }
    }*/
    

    
}

int main() 
{
    string s, r;
    cin >> s;
    
    //int a[26] = {0};
    r = is_pangram(s);
    cout << r;
    
    
    return 0;
}
