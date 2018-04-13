#include <bits/stdc++.h>

using namespace std;

bool isLeapYear(int x)
{
    return( (x%400 == 0) || (x%4 == 0 && x%100 !=0) );
}

//In julian calendar leap years are divisible by 4...

string solve(int year)
{
    if(year == 1918)
    {
        return "26.09.2017";
    }
    else
    {
        if(!isLeapYear(year))
        {
            string s = "13.09." + to_string(year);
            return s;
        }
        else
        {
            string s = "12.09." + to_string(year);
            return s;
        }
    }
}

int main()
{
    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}
