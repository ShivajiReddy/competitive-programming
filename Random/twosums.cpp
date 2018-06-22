#include <bits/stdc++.h>
using namespace std;

void twoSums(vector<int> v, int target)
{
	//returns index after sorting
	sort(v.begin(), v.end());
	int l = 0, r = v.size()-1;
	while(l < r)
	{
		if(v[l] + v[r] == target)
		{
			printf("%d %d\n", l+1, r+1);
			return;
		}
		else if(v[l] + v[r] < target) l++;
		else r--;
	}
	cout << "No possible pairs\n";
	
}

void twosums_bruteforce(vector<int> v, int target)
{
	int n = v.size();
	for (int i = 0; i < n; ++i)
	{
		for(int j = 1; j < n; j++)
		{
			if(v[i] + v[j] == target) 
			{
				printf("%d %d\n", i+1, j+1);
				return;
			}	
		}
	}

}

int main(int argc, char const *argv[])
{
	int n, target;
	cin >> n >> target;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	twosums_bruteforce(v, target);
	twoSums(v, target);
	return 0;
}