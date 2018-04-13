#include <bits/stdc++.h>

using namespace std;

int calculate_max_sum(vector<int> a, int n)
{
    // sorts the array c++ stl
    sort(a.begin(), a.end());
 
    int max_sum = 0;
 
    // traverse to find the maximum sum
    for (int i = 0; i < n / 2; i++) {
         
        // the farthest distant elemnts sum 
        // will always be maximum
        max_sum += abs(a[n - 1 - i] - a[i]);
    }
    return max_sum;
}

/*int minimumTime(vector <int> x) 
{
    for(int ) 
}*/

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> x(n);
        //int x[n];
        for(int x_i = 0; x_i < n; x_i++){
           cin >> x[x_i];
        }
        int result = calculate_max_sum(x, n);
        cout << result << endl;
    }
    return 0;
}
