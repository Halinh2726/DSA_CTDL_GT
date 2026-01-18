#include<bits/stdc++.h>
using namespace std;

int n, ok = 1;
string s;

void sinh()
{
    cin >> s;
    int i = s.size() - 1;
    while(i>= 0 && s[i] == '0')
    {
        s[i] = '1';
        i--;
    }
    if(i >= 0)
    {
       s[i] = '0';
    }
    cout << s << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        sinh();
    }
    return 0;
}