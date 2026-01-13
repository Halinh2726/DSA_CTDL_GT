#include<bits/stdc++.h>
using namespace std;

string s;
void Solve()
{
    cin >> s;
    int i = s.size()-1;
    while(i>= 0 && s[i] == '1')
    {
        s[i] = '0';
        --i;
    }
    if(i >= 0 ) s[i] = '1';
    cout << s <<"\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        Solve();
    }
    return 0;
}