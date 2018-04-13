#include <bits/stdc++.h>

using namespace std;

int chocolateFeast(int n, int c, int m)
{
    //10 2 5 = 6
    int ch_bought = n/c;
    int total = ch_bought;
    int wrappers = ch_bought;
    while(wrappers >= m)
    {
        int ch_wrapp = wrappers/m;
        total += ch_wrapp;
        wrappers = (wrappers%m) + ch_wrapp;
    }

    return total;
}

int main() 
{
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        int result = chocolateFeast(n, c, m);
        cout << result << endl;
    }
    return 0;
}
