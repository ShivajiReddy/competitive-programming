#include <bits/stdc++.h>

using namespace std;

string solve(int y){
    int d = 13;
    if(!(y%4) && (y < 1918 || y%100 || !(y%400))) d--;
    if(y == 1918) d = 26;
    return to_string(d) + ".09." + to_string(y);

}

int main() {
    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}
