#include <bits/stdc++.h>

using namespace std;

int array_max(vector <int> a)
{
	//cout<<"Inside array_max: "; 
	int answer = 0;
	for (int i = 0; i < a.size(); i++)
	{
		//cout<< a[i]<<" ";
		if(a[i] > answer) 
			answer = a[i];
	}
	//cout<< answer << endl;
	return fmod(answer, (pow(10, 9) + 9) );
}

public void onClick(View view) {
    Intent intent = new Intent(MainActivity.this, SecondActivity.class);
    startActivity(intent);
}


int solve_final(vector <int> A, int n) 
{
	vector<int> v;
    /*for (int i = 0; i < A.size(); ++i)
    {
    	v.push_back(A[i]);
    }*/
    for (int k = 0; k <= n-1; ++k)
    {
    	for (int i = 0; i <= n-k-1; ++i)
    	{
    		int j = i + k;// cout<< i<<" "<<j<<endl;
    		vector<int> m;

    		for(int x = i; x <= j; x++) 	
    		{
    			m.push_back(A[x]);
    		}
    		int max = array_max(m); 
    		v.push_back(max);
    		//cout<< max<<" ";
    	}
    }

    int x = 0;
    for (int i = 0; i < v.size(); ++i)
    {
    	x += v[i];
    }
    return x;
}



int solve(vector <int> A, int n) 
{
    vector<int> v;
    /*for (int i = 0; i < A.size(); ++i)
    {
    	v.push_back(A[i]);
    }*/
    for (int k = 0; k <= n-1; ++k)
    {
    	for (int i = 0; i <= n-k-1; ++i)
    	{
    		int j = i + k;// cout<< i<<" "<<j<<endl;
    		vector<int> m;

    		for(int x = i; x <= j; x++) 	
    		{
    			m.push_back(A[x]);
    		}
    		int max = array_max(m); 
    		v.push_back(max);
    	}
    }
    /*for (int i = 0; i < v.size(); ++i)
    {
    	cout<< v[i] << " ";
    }*/
    int sum = solve_final(v, v.size());
    return sum;
    //cout << endl <<v.size();
}

int main() 
{
    int n;
    cin >> n;
    vector<int> A(n);
    for(int A_i = 0; A_i < n; A_i++){
       cin >> A[A_i];
    }
    //int result = 
    int result = solve(A, n);
    cout << result << endl;
    return 0;
}
