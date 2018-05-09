// C++ program to find minimum number of denominations
#include <bits/stdc++.h>
using namespace std;
 
// All denominations of Indian Currency
int deno[] = {1, 5, 10};
int n = sizeof(deno)/sizeof(deno[0]);
 
// Driver program
void findMin(int V)
{
    // Initialize result
    vector<int> ans;
 
    
    for (int i=n-1; i>=0; i--)
    {
        // Find denominations
        while (V >= deno[i])
        {
           V -= deno[i];
           ans.push_back(deno[i]);
        }
    }
 
    cout << ans.size();
}
 
// Driver program
int main()
{
   int n;
   cin >> n;
   findMin(n);
   return 0;
}