#include <bits/stdc++.h>

using namespace std;

vector < int > solve(vector < int > grades)
{
    // Complete this function
    int n = grades.size();
    vector < int > results(n);
    //results = grades;
    
    for(int i = 0; i < n; i++)
    {
        if(grades[i] < 38 || grades[i] % 5 == 0 || grades[i] % 5 < 3 )
        {
            results[i] = grades[i];
        }
        
        else
        {
            int diff = 5 - (grades[i] % 5);
            results[i] = grades[i] + diff; 
        }
    }

    return results;
}

int main() 
{
    int n;
    cin >> n;
    vector<int> grades(n);
    for(int grades_i = 0; grades_i < n; grades_i++){
       cin >> grades[grades_i];
    }
    vector < int > result = solve(grades);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;
    

    return 0;
}
