#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, h, doses;
    cin >> n >> h;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    doses = v[n-1]-h;
    
    if(doses > 0) cout << doses;
    else cout << 0;
    
    return 0;
}

