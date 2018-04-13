#include <bits/stdc++.h>

using namespace std;

/*long getWays(long n, vector < long > c){
    // Complete this function
}*/

int count( vector<int> S, int m, int n )
{
    // If n is 0 then there is 1 solution 
    // (do not include any coin)
    if (n == 0)
        return 1;
     
    // If n is less than 0 then no 
    // solution exists
    if (n < 0)
        return 0;
 
    // If there are no coins and n 
    // is greater than 0, then no
    // solution exist
    if (m <=0 && n >= 1)
        return 0;
 
    // count is sum of solutions (i) 
    // including S[m-1] (ii) excluding S[m-1]
    return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> arr(m);
    for(int i = 0; i < m; i++){
       cin >> arr[i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    int x = count(arr, m, n);
    cout << x << endl;
    return 0;
}
