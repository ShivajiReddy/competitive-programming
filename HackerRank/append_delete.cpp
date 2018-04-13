#include <bits/stdc++.h>


using namespace std;

int main()
{
    string s, t;
    int k, i = 0;
    cin >> s >> t >> k;
    int L = s.size() + t.size();
    
    while(s[i] == t[i]) i++;
    cout << (L <= k + i*2 && L%2 == k%2 || L < k ? "Yes" : "No");
    
    return 0;
}