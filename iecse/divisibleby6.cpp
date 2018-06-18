#include <bits/stdc++.h>
using namespace std;
 
int greatest(string s)
{
    int n = s.length();
    int a[n];
 
    // stores the sum of all elements
    int sum = 0;
 
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
        sum += a[i];
    }
 
    if (a[n - 1] % 2) // ODD CHECK
    {
        if (a[n - 2] % 2 != 0 or (sum - a[n - 1]) % 3 != 0) {
            return -1;
        }
 
        
        else {
            return n;
        }
    }
    else {
        int re = sum % 3;
        int del = -1;
 
        // counter to check if any
        // element after removing,
        // its sum%3==0
        int flag = 0;
 
        // traverse till second last element
        for (int i = 0; i < n - 1; i++) {
 
            // to check if any element
            // after removing,
            // its sum%3==0
            if ((a[i]) % 3 == re) {
     
                // the leftmost element
                if (a[i + 1] > a[i]) {
                    del = i;
                    flag = 1;
 
                    // break at the leftmost
                    // element
                    break;
                }
                else {
                    // stores the right most
                    // element
                    del = i;
                }
            }
        }
 
        // if no element has been found
        // as a[i+1]>a[i]
        if (flag == 0) {
     
            // if second last is even, then
            // remove last if (sum-last)%3==0
            if (a[n - 2] % 2 == 0 and re == a[n - 1] % 3)
                del = n - 1;
        }
 
        // if no element which on removing
        // gives sum%3==0
        if (del == -1)
            return -1;
        else {
            return del + 1;
        }
    }
}
 

int main()
{
    int n; 
    cin >> n;
    string input[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> input[i];
    }
    for (int j = 0; j < n; ++j)
    {
        string s = input[j];
        int x;
        x = greatest(s)-1;
        if(x == -2) cout << -1;
        else
        {
            for(int i = 0; i < s.size(); i++)
            {
                if( i != x) cout << s[i];
            }   
        }
        cout << endl;    
    }
    
    return 0;
}