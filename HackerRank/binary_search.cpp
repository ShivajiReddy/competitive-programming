#include <bits/stdc++.h>
using namespace std;

// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
string binarySearch(int arr[], int l, int r, int x)
{
   cout << l <<" "<< r << endl;	
   if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)  return "Found";
 
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
 
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
   }
 
   // We reach here when element is not present in array
   return "Not found";
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n, x; 
		cin >> n;
		int a[n];
		for (int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		cin >> x;
		string result = binarySearch(a, 0, n-1, x);
		cout << result << endl;
	}
	return 0;
}