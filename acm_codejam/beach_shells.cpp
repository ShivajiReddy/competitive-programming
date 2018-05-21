#include <bits/stdc++.h>
using namespace std;


void findMin(int V, vector<int> deno)
{
    // Initialize result
    vector<int> ans;
    int n = deno.size();
    
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

 
int main(int argc, char const *argv[])
{
    int n, r, f;
    cin >> n >> r >> f;
    vector<int> shiny_val(n);
    vector<int> num(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> shiny_val[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> num[i];
    }

    int net_val = 0;
    for (int i = 0; i < n; ++i)
    {
        net_val += (shiny_val[i] * num[i]);
    }

    vector<int> deno(n);
    deno = shiny_val;
    //cout << net_val/(r+f) << endl;
    /*for (int i = 0; i < n; ++i)
    {
        cout << deno[i] << " ";
    }*/

    findMin(net_val/(r+f), deno);
    
    return 0;
}