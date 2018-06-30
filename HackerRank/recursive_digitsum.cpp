#include <bits/stdc++.h>
using namespace std;

int super_digit(string p)
{
	if (p.size() == 1)
		return stoi(p);
	else
	{
		int sum = 0;
		for (int i = 0; i < p.size(); ++i)
		{
			sum = sum + (p[i]-'0');
		}
		return super_digit(to_string(sum));		
	}
	
}
void generate_p(string n, int k)
{
	int n_size = n.size();
	string p;
	p = n;

	for (int i = n_size; i < k*n_size; ++i)
	{
		p += n[i%n_size];
	}
	//cout << p << endl;
	cout << super_digit(p);
}


int main(int argc, char const *argv[])
{
	string n;
	int k;
	cin >> n >> k;
	//cout << 
	generate_p(n, k);

	return 0;
}