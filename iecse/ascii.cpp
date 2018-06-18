#include <bits/stdc++.h>
using namespace std;

//65 to 90
void solve(int t)
{
	vector<int> v(10, 0);
	vector<int> letters;
	while(t > 0)
	{
		v[t%10]++;
		t = t/10;
	}
	/*for (int i = 0; i < 10; ++i)
	{
		cout << v[i] << " ";
	}*/
	if(v[6] > 1) letters.push_back(66);
	if(v[7] > 1) letters.push_back(77);
	for (int i = 6; i <= 9; ++i)
	{
		if(v[i] != 0)
		{
			for (int j = 0; j < 10; ++j)
			{
				if(v[j] != 0 && i != j) 
				{
					int number = (i*10) + j;
					if(number >= 65 && number <= 90) letters.push_back(number);
				}

				//{ letters.push_back((i*10) + j); }
			}
		}
	}
	sort(letters.begin(), letters.end());
	for (int i = 0; i < letters.size(); ++i)
	{
		cout << (char)letters[i];
	}
	cout << endl;

}

int main()
{
    int n; 
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> input[i];
    }
    for (int j = 0; j < n; ++j)
    {
        int t = input[j];
        //int length = (t == 0) ? 1 : 1 + (int)log10(t);
        //cout << "length: " << length << endl;
        solve(t);//, length);   
    }
    
    return 0;
};